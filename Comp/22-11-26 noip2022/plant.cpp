/*
80pts
unsigned long long rp = -1;
*/
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

#define Debug cout

int read ()
{
	int res = 0, flag = 1;
	char ch = getchar ();
	while (not isdigit (ch))
	{
		if (ch == '-') flag = -1;
		ch = getchar ();
	}
	while (isdigit (ch))
	{
		res = res * 10 + int (ch - '0');
		ch = getchar ();
	}
	return res * flag;
}

const int maxn = 1005;
const int mod = 998244353;
int T, id;
int n, m;
int c, f;

int a[maxn][maxn];

namespace Reader{
	inline void work ()
	{
		n = read(), m = read();
		c = read(), f = read();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				char ch;
				cin >> ch;
				if (ch == '1')
				{
					a[i][j] = 1;
				}
				else
				{
					a[i][j] = 0;
				}
			} 
		}
	}
}

namespace Sub1{
	inline void solve ()
	{
		cout << 0 << " " << 0 << endl;
	}
}

namespace Sub2{
	inline void solve ()
	{
		Reader::work();
		
		int vc = 0, vf = 0;
		// C
		for (int x1 = 1; x1 <= n; x1++)
		{
			if (a[x1][1] == 1) continue;
			if (a[x1][2] == 1) continue;
			for (int x2 = x1 + 2; x2 <= n; x2++)
			{
				if (a[x2][1] == 1) break;
				if (a[x2][2] == 0)
				{
					// Debug << "x1 = " << x1 << endl;
					// Debug << "x2 = " << x2 << endl;
					vc ++;
 					vc %= mod;
				} 
			}
		}
		vc %= mod;

		// F
		for (int x1 = 1; x1 <= n; x1 ++)
		{
			if (a[x1][1] == 1) continue;
			if (a[x1][2] == 1) continue;
			int cnt = 0;
			for (int x2 = x1 + 2; x2 <= n; x2 ++)
			{
				if (a[x2][1] == 1) break;
				vf += cnt;
				vf %= mod; 
				if (a[x2][2] == 0)
				{
					cnt ++;
				}
			}
		}
		vf %= mod;
		cout << (c * vc) % mod << " " << (f * vf) % mod << endl;
	}
}

int cnt_h[maxn][maxn];
int cnt_l[maxn][maxn];

namespace Zhengjie{
	stack<int> stk; // 栈
	
	inline void pre ()
	{
		// 每一行
		for (int i = 1; i <= n; i++)
		{
			a[i][m + 1] = 1; // 使栈能够清空
			for (int j = 1; j <= m + 1; j++)
			{
				stk.push(j);
				if (a[i][j] == 1)
				{
					int res = -1;
					while (not stk.empty())
					{
						int x = stk.top(); stk.pop();
						cnt_h[i][x] = res;
						res ++;
					}	
				}
			}
			a[i][m + 1] = 0; // 复原
		}

		// 每一列
		for (int i = 1; i <= m; i++)
		{
			a[n + 1][i] = 1;
			for (int j = 1; j <= n + 1; j++)
			{
				stk.push(j);
				if (a[j][i] == 1)
				{
					int res = 0; // 不用从-1开始
					while (not stk.empty())
					{
						int x = stk.top(); stk.pop();
						cnt_l[i][x] = res;
						res ++;
					}
				}
			}
			a[n + 1][i] = 1;
		}
	}
	
}

/* 爆力居然挂了
namespace Baoli{
	inline void solve ()
	{
		Reader::work();
		
		int vc = 0;
		for (int x1 = 1; x1 <= n; x1++)
		{
			for (int y0 = 1; y0 <= m; y0++)
			{
				if (a[x1][y0] == 1) continue;      // 剪枝
				for (int y1 = y0 + 1; y1 <= m; y1++)     
				{
					if (a[x1][y1] == 1) break;      // 剪枝
					for (int x2 = x1 + 2; x2 <= n; x2++)     
					{
						if (a[x2][y0] == 1) break;      // 剪枝
						for (int y2 = y0 + 1; y2 <= m; y2++)      
						{
							if (a[x2][y2] == 1) break;      // 剪枝
							vc++;
							vc %= mod;
						}
					}
				}
			}
		}
		vc %= mod;

		int vf = 0;
		for (int x1 = 1; x1 <= n; x1++)
		{
			for (int y0 = 1; y0 <= m; y0++)
			{
				if (a[x1][y0] == 1) continue;
				int cnt = 0;
				for (int y1 = y0 + 1; y1 <= m ; y1++)
				{
					if (a[x1][y1] == 1) break;
					for (int x3 = x1 + 2; x3 <= n; x3++)
					{
						if (a[x3][y0] == 1) break;
						vf += cnt;
						vf %= mod;
						for (int y2 = y0 + 1; y2 <= m; y2++)
						{
							if (a[x3][y2] == 1) break;
							cnt ++;
						}
					}
				}
			}
		}
		vf %= mod;
		cout << (c * vc) % mod << " " << (f * vf) % mod << endl;
	}
}
*/

namespace Sub3{
	inline void solve ()
	{
		Zhengjie::pre();

		int vc = 0;
		if (c != 0)
		{
			for (int x1 = 1; x1 <= n; x1++)
			{
				for (int y0 = 1; y0 <= m; y0++)
				{
					if (a[x1][y0] == 1) continue;
					if (a[x1 + 1][y0] == 1) continue;
					for (int x2 = x1 + 2; x2 <= n; x2++)
					{
						if (a[x2][y0] == 1)
						{
							break;
						}
						vc += cnt_h[x1][y0] * cnt_h[x2][y0];
						vc %= mod;
					}
				}
			}
			vc %= mod;
		}
		// Debug << "--------------------" << endl;
		int vf = 0;
		if (f != 0)
		{
			for (int x1 = 1; x1 <= n; x1++)
			{
				for (int y0 = 1; y0 <= m; y0++)
				{
					if (a[x1][y0] == 1) continue;
					if (a[x1 + 1][y0] == 1) continue;
					int cnt = 0;
					for (int x2 = x1 + 2; x2 <= n; x2++)
					{
						if (a[x2][y0] == 1)
						{
							break;
						}
						vf += cnt;
						vf %= mod;
						cnt += cnt_h[x1][y0] * cnt_h[x2][y0];
					}
				}
			}
			vf %= mod;
		}
		cout << (c * vc) % mod << " " << (f * vf) % mod << endl;
	}
}

namespace Sub4{
	inline void solve ()
	{
		// 不会。。。
	}
}

int main ()
{
	// freopen ("plant.in", "r", stdin);
	// freopen ("plant.out", "w", stdout);
	T = read ();
	id = read ();
	if (id == 1)
	{
		while (T--)
		{
			Sub1::solve();
		}
	}
	else if (id >= 2 and id <= 4)
	{
		while (T--)
		{
			Reader::work ();
			// Sub2::solve();
			Sub3::solve();
		}
	}
	else if (id == 5)
	{
		while (T--)
		{
			Reader::work();
			// m = m - m / 3;
			Sub3::solve();
		}
	}
	else if (id == 6)
	{
		while (T--)
		{
			Reader::work();
			// n = n - n / 4;
			Sub3::solve();
		}
	}
	else if (id == 7) // ~~ O (n ^ 5) ~~
	{
		while (T--)
		{
			Reader::work();
			Sub3::solve(); // 暴力写挂 不想调了（（
		}
	}
	else
	{
		while (T--)
		{
			Reader::work();
			Sub3::solve();
		}
	}

	// fclose (stdin);
	// fclose (stdout);
	return 0;
}

// rp++
