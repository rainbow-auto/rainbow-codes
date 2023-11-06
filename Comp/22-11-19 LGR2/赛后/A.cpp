#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 500005;

int T;
int n;

int px[maxn];
int py[maxn];

namespace Ans2{
	bool solve ()
	{
		if (px[n / 2] != px[n / 2 + 1])
		{
			cout << 2 << endl;
			return true;
		}
		if (py[n / 2] != py[n / 2 + 1])
		{
			cout << 2 << endl;
			return true;
		}
		return false;
	}
}

struct Point{
	int x, y;
	friend bool operator < (Point a, Point b)
	{
		if (a.x == b.x)
		{
			return a.y > b.y;
		}
		else
		{
			return a.x > b.x;
		}
	}
};
Point ps[maxn];

namespace Ans3{
	int ys[maxn];
	bool solve ()
	{
		sort (ps + 1, ps + n + 1);
		int l = 1; // 右边数第一列 
		int r;
		int k = 0x3f3f3f3f3f;
		while (l <= n)
		{
			r = l;
			while (r + 1 <= n and ps[r + 1].x == ps[l].x) //加入一列
			{
				r++;	
			}
			
			for (int i = l; i <= r; i++)
			{
				
			}
		}
	}
}

int main ()
{
	cin >> T;
	while (T --)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> px[i] >> py[i];	
			ps[i].x = px[i];
			ps[i].y = py[i];
		}
		sort (px + 1, px + n + 1);
		sort (py + 1, py + n + 1);
		
		// ans = 2
		if (Ans2::solve ()) continue;
		
		// ans = 3
		
	}		
	return 0;
}

