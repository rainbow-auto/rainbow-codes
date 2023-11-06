#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int mod = 2e5 + 1;
const int maxn = 400005;

struct Line{
	int l, r;
	friend bool operator < (Line a, Line b)
	{
		if (a.l == b.l)
		{
			return a.r < b.r;
		}
		else
		{
			return a.l < b.l;
		}
	}
};

int type;
int q;

struct Query{
	int t, l, r;
};
Query qs[maxn];

namespace Sub1{
	set <Line> ls;
	typedef set<Line>::iterator sit; 
	
	inline void op1 (int l, int r)
	{
		ls.insert(Line{l, r});
	} 
	
	inline Line intersect (Line a, Line b)
	{
		Line res = Line{max(a.l, b.l), min(a.r, b.r)};
		if (res.l <= res.r)
		{
			return res;
		}
		else
		{
			return Line{-1, -1}; 
		}
	}
	
	inline void op2 (int l, int r)
	{
		sit begin = ls.lower_bound(ls.begin(), ls.end(), Line{l, l});
		sit end = ls.upper_bound(ls.begin(), ls.end(), Line{r, r}); 
		for (sit it = ls.begin(); i != ls.end(); it++)
		{
			Line its = intersect (Line{l, r}, *it);
			if (its.l != -1 and its.r != -1)
			{
				*it = its;
			}
		}
	}
	
	inline int op3 (int l, int r)
	{
		int res = 0;
		for (sit i = ls.begin(); i != ls.end(); it++)
		{
			Line its = intersect (Line{l, r}, *it);
			if (its.l != -1 and its.r != -1)
			{
				res += its.r - its.l;	
			}
		}
		return res;
	}
	
	void solve ()
	{
		int lastans = 0;
		for (int i = 1; i <= q; i++)
		{
			int t = qs[i].t;
			int l = qs[i].l;
			int r = qs[i].r;
			l = (l + type * lastans) % mod;
			r = (r + type * lastans) % mod;
			if (t == 1)
			{
				op1 (l, r);	
			} 
			else if (t == 2)
			{
				op2 (l, r);
			}
			else if (t == 3)
			{
				lastans = op3 (l, r);
				cout << lastans << endl;
			}
		}	
	}
}

int main ()
{
	cin >> q >> type;
	
	int k1 = 0, k2 = 0, k3 = 0;
	for (int i = 1; i <= q; i++)
	{
		cin >> qs[i].t >> qs[i].l >> qs[i].r;
		if (qs[i].t == 1)
		{
			k1 ++;	
		}		
		else if (qs[i].t == 2)
		{
			k2 ++;
		}
		else if (qs[i].t == 3)
		{
			k3 ++;
		}
	}	
	
	if (k1 <= 100 and k2 <= 100 and k3 <= 100)
	{
		Sub1::solve ();
	}
	
	return 0;
}

