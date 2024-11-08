/*
思路有点小问题

添加 rnk_up 和 rnk_down 处理向上和向下的情况 
 
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 600005;

int to[maxn], pre[maxn], last[maxn];
int cnt;
inline void addEdge (int u, int v)
{
	cnt ++;
	to[cnt] = v;
	pre[cnt] = last[u];
	last[u] = cnt;
}

struct Plan {
	int s, t;
}p[maxn];

int n, m;
int w[maxn];

namespace TreeDecomp { // Tree-Decomposition
	int siz[maxn], son[maxn], fa[maxn], dep[maxn];
	void tree_build(int now)
	{
		siz[now] = 1;
		
		int siz_k = -1, siz_t = 0;
		for (int i = last[now]; i; i = pre[i])
		{
			int t = to[i];
			if (siz[t]) continue;
			fa[t] = now;
			dep[t] = dep[now] + 1;
			tree_build (t);
			siz[now] += siz[t];
			if (siz_t < siz[t])
			{
				siz_t = siz[t];
				siz_k = t;
			}
		}
		son[now] = siz_k;
	}
		
	int top[maxn], rnk[maxn], bottom[maxn], dfn[maxn], dpos;
	void tree_decomp (int now, int topnow)
	{
		dfn[now] = ++dpos;
		top[now] = topnow;
		rnk[dpos] = now;
		bottom[now] = dpos;
		
		if (son[now] == -1) return;
		
		tree_decomp (son[now], topnow);
		bottom[now] = max (bottom[now], bottom[son[now]]);
		for (int i = last[now]; i; i = pre[i])
		{
			int t = to[i];
			if (t == fa[now]) continue;
			if (t == son[now]) continue;
			tree_decomp (t, t);
			bottom[now] = max (bottom[now], bottom[t]);
		}
	}		
	
	void work ()
	{
		dep[1] = 1;
		tree_build (1);
		tree_decomp (1, 1);
	}
}

namespace Solution {
	int ans[maxn];
	
	vector<int> rnk[maxn];
	int tot;
	
	inline void prepare ()
	{
		TreeDecomp::work();
		
		cout << "dfn: " ;
		for (int i = 1; i <= n; i++)
		{
			cout << TreeDecomp::dfn[i] << " ";
		}
		cout << endl;
		
		for (int i = 1; i <= m; i++)
		{
			rnk[TreeDecomp::dep[p[i].s]].push_back(TreeDecomp::dfn[p[i].s]);
			tot = max (tot, TreeDecomp::dfn[p[i].s]);
		}
		
		for (int i = 1; i <= tot; i++)
		{
			sort (rnk[i].begin(), rnk[i].end());
		}
		
		for (int i = 1; i <= n; i++)
		{
			cout << "dep: " << i << " "; 
			for (int j = 0; j < rnk[i].size(); j++)
			{
				cout << rnk[i][j] << " ";
			}
			cout << endl;
		}		
	}
	
	inline int search (int x, int d, bool flag)
	{
//		int l = rnk[d].upper_bound (TreeDecomp::dfn[x] - 1) - rnk[d].begin(); // >(dfn[x] - 1)的下一个元素 === >= dfn[x]
//		int r = rnk[d].lower_bound (TreeDecomp::bottom[x]) - rnk[d].begin();  // <=bottom[x] 
		
		int l = upper_bound (rnk[d].begin(), rnk[d].end(), TreeDecomp::dfn[x] - 1) - rnk[d].begin();
		int r = lower_bound (rnk[d].begin(), rnk[d].end(), TreeDecomp::bottom[x]) - rnk[d].begin();
		
		int res = 0;		
		if (flag) // 子树内 
		{
			res = max (res, r - l + 1); 
		}
		else
		{
			res = max (res, int(rnk[d].size() - (r - l + 1)));
		}
		return res;
	} 
	
	inline void solve ()
	{
		prepare ();
		
		for (int i = 1; i <= n; i++)
		{
			ans[i] = search (i, w[i] + TreeDecomp::dep[i], true) + search (i, w[i] - TreeDecomp::dep[i], false);
			cout << "i = " << i << endl;
			cout << search (i, w[i] + TreeDecomp::dep[i], true) << endl; 
			cout << search (i, w[i] - TreeDecomp::dep[i], false) << endl;
		}
	}
}

int main ()
{
	fastread
	
	cin >> n >> m;
	for (int i = 1; i <= n - 1; i ++)
	{
		int u, v;
		cin >> u >> v;
		addEdge (u, v);
		addEdge (v, u);
	}
	
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	
	for (int i = 1; i <= m; i++)
	{
		cin >> p[i].s >> p[i].t;	
	}	
	
	cout << "ok" << endl;
	
	Solution::solve();
	
	for (int i = 1; i <= n; i++)
	{
		cout << Solution::ans[i] << endl;
	}
	
	return 0;
}
