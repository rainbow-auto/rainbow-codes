#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int maxn = 2505;
const int maxk = 105;

int n, m, k;

long long v[maxn];
long long dis[maxn][maxn];

namespace Sub1{
	
	bool vis[maxn];
	int root;
	
	inline void floyd ()
	{
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (i == j) dis[i][j] = 0;
					else dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
	}
	
	void solve ()
	{
		#define For(i, n) for (int i = 2; i <= n; i++)
		floyd ();
		k++;
		long long ans = 0;
//		For (a, n)
		for (int a = 2; a <= n; a++)
		{
			if (dis[1][a] > k)
			{
				continue;
			}
//			For (b, n)
			for (int b = 2; b <= n; b++)
			{
				if (dis[a][b] > k)
				{
					continue;
				}
				if (b == a) 
				{
					continue;
				}
//				For (c, n)
				for (int c = 2; c <= n; c++)
				{
					if (dis[b][c] > k)
					{
						continue;
					}
					if (c == a or c == b)
					{
						continue; 
					}
//					For (d, n)
					for (int d = 2; d <= n; d++)
					{
						if (dis[c][d] > k)
						{
							continue;
						}
						if (dis[d][1] > k)
						{
							continue;	
						}
						
						if (d == a or d == b or d == c)
						{
							continue;
						}
						
						if (ans < v[a] + v[b] + v[c] + v[d])
						{
							ans = v[a] + v[b] + v[c] + v[d];
						}
					}
				}
			}
		}
		
		cout << ans << endl; 
	}
}

int main ()
{
	memset (dis, 0x3f, sizeof (dis));
	cin >> n >> m >> k;	
	
	for (int i = 2; i <= n; i++)
	{
		cin >> v[i];	
	}	
 
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		dis[u][v] = 1;
		dis[v][u] = 1;
	}
		
	Sub1::solve ();	
	return 0;
}

