#include <iostream>

using namespace std;
const int maxn = 100005;

int n;
int a[maxn];
int t[maxn];

namespace Tree{
	int tr[maxn * 8];
		
	#define lson x << 1
	#define rson x << 1 | 1
		
	void make_tree (int x, int l, int r)
	{
		if (l == r)
		{
			tr[x] = t[l];
			return;
		}
		
		int mid = (l + r) >> 1;
		make_tree (lson, l, mid);
		make_tree (rson, mid + 1, r);
		tr[x] = tr[lson] + tr[rson];
	}
	
	int query (int x, int l, int r, int L, int R)
	{
		if (L <= l and R >= r)
		{
			return tr[x];		
		}
		
		int mid = (l + r) >> 1;
		int res = 0;
		if (L <= mid)
		{
			res += query (lson, l, mid, L, R);
		}
		if (R > mid)
		{
			res += query (rson, mid + 1, r, L, R);	
		}	
		return res;
	}

	void update (int x, int l, int r, int pos, int val)
	{
		if (l == r)
		{
			tr[x] = val;
			return;	
		}		
		
		int mid = (l + r) >> 1;
		
		if (pos <= mid)
		{
			update (lson, l, mid, pos, val);
		}
		else
		{
			update (rson, mid + 1, r, pos, val);
		}
		tr[x] = tr[lson] + tr[rson];
	}
}

namespace Solution{
	bool solve ()
	{
		memset (t, 0, sizeof (t));
		Tree::make_tree (1, 1, n);
		
		for (int i = 1; i <= n; i++)		
		{
			t[a[i]] ++;
			Tree::update (1, 1, n, a[i], t[a[i]]);
		}
		
		int maxp = 0;
		int maxx = 0;
				
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > maxx)		
			{
				int last = maxp;
				maxp = i;
				maxx = a[i];
			}
			
			t[a[i]] --;
			Tree::update (1, 1, n, a[i], t[a[i]]);
	
//			for (int j = a[i]; j <= maxx; j++) cout << t[j] << " ";
//			cout << endl;			
			
			if (a[i] > maxx) continue;
				 								
			if (Tree::query (1, 1, n, a[i], maxx))
			{
				return false;
			}			
			
		}
		return true;
	}
}

//#define debug

int main ()
{
	#ifdef debug
	
	freopen ("data.in", "r", stdin);
	freopen ("ans2.out", "w", stdout);
	#endif
	
	while (true)
	{
		cin >> n;
		if (n == 0) break;
		
		bool flag = false;
		while (true)
		{
			for (int i = 1; i <= n; i++)
			{
				cin >> a[i];
				if (a[i] == 0)
				{
					flag = true;
					break;	
				} 
			}
			if (flag) break;	
			
			if (Solution::solve ())
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
		cout << endl;
	}
	
	return 0;
}