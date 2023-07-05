#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int maxn = 10005;

int T;

int n;
int a[maxn];

namespace Task1{ // O(n ^ 3)
	void solve ()
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				if (a[j] >= a[i]) continue;
				for (int k = j; k <= n; k++)
				{
					if (a[k] >= a[i]) continue;
					
					if (a[j] < a[k])
					{
						cout << "No" << endl;
						return;
					}
				}
			}
		}
		cout << "Yes" << endl;
	}
} 

namespace Task2{ // O(n ^ 3)
	int p[maxn];
	
	void init ()
	{
		int curr_max = 0;
		int curr_p = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > curr_max)
			{
				curr_max = a[i];
				curr_p = i;
			}
			p[i] = curr_p;
		}
	}
	
	void solve ()
	{
		init ();
		
		for (int j = 1; j <= n; j++)
		{
			int i = p[j];
			
			if (a[j] >= a[i]) continue;
			for (int k = j + 1; k <= n; k++)
			{
				if (a[k] >= a[i]) continue;
				
				if (a[j] < a[k])
				{
					cout << "No" << endl;
					return;
				}				
			}	
		}
		cout << "Yes" << endl;
	}
}

namespace Task3{ // O (n log n)
	struct Node{
		int l, r;
		int x;
	};
	
	Node tr[maxn];
	
	void make_tree (int l, int r, int x)
	{
		if (l == r)
		{
			tr[x].x = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		make_tree (l, mid, x << 1);
		make_tree (mid + 1, r, x << 1 | 1);
		tr[x].x = min (tr[x << 1].x, tr[x << 1 | 1].x);
		tr[x].l = l;
		tr[x].r = r;
	}
	
	int query(int l, int r, int L, int R, int x)
	{
		if (l == r)
		{
			return tr[x].x;
		}
			
		if (L <= l and R >= r)
		{
			return tr[x].x;	
		}	
			
		int res = 0x3f3f3f3f;
		int mid = (l + r) >> 1;	
		if (L <= mid)	
		{
			res = min (res, query (l, mid, L, R, x << 1));
		}
		if (R > mid)
		{
			res = min (res, query (mid + 1, r, L, R, x << 1 | 1));
		}
		return res;
	} 
	
	int p[maxn];
	void init ()
	{
		int curr_max = 0;
		int curr_p = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > curr_max)
			{
				curr_max = a[i];
				curr_p = i;
			}
			p[i] = curr_p;
		}
	}
	
	void solve ()
	{
		init ();
		make_tree (1, n, 1);
		
		for (int k = 1; k <= n; k++)
		{
			int i = p[i];
			int aj = query (1, n, i, k, 1);
			
			if (aj >= a[i]) continue;
			if (a[k] >= a[i]) continue;
			
			if (aj < a[k])
			{
				cout << "No" << endl;	
				return;
			}		
		}
		cout << "Yes" << endl;
	}
}

#define debug
#define t1

int main ()
{
	#ifdef debug
	
	freopen ("data.in", "r", stdin);
	
	#ifdef t1
	freopen ("ans1", "w", stdout);
	#endif
	
	#ifdef t3
	freopen ("ans2", "w", stdout);
	#endif
	
	#endif
	
	cin >> T;

	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		
		#ifdef t1
		Task1::solve();
		#endif
		
		#ifdef t3
		Task3::solve();
		#endif
		
//		if (n <= 100)
//		{
//			Task1::solve();
//		}
//		else if (n <= 2000)
//		{
//			Task2::solve();
//		}
//		else
//		{
//			Task3::solve();
//		}
	}	
	
	return 0;
}
