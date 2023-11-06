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

const int maxn = 600005;

int T;
int n;

int cnt;
int from[maxn], to[maxn], pre[maxn], last[maxn];
bool ex[maxn];

inline void addEdge (int u, int v)
{
	cnt++;
	from[cnt] = u;
	to[cnt] = v;
	pre[cnt] = last[u];
	last[u] = cnt;
}

inline void clear ()
{
	memset (ex, 1, sizeof (ex));
	memset (from, 0, sizeof (from));
	memset (to, 0, sizeof (to));
	memset (pre, 0, sizeof (pre));
	memset (last, 0, sizeof (last));
	cnt = 0;	
} 

int ansnow;
int siz[maxn];
int wht[maxn];
int mi;
void dfs (int now, int fa)
{
	wht[now] = 0; 	
	siz[now] = 1;
	for (int i = last[now]; i; i = pre[i])
	{
		int t = to[i];
		if (t == fa) continue;
		if (not ex[i]) continue;
		dfs (t, now); 
		siz[now] += siz[t];
		wht[now] = max (wht[now], siz[t]);
	}
	wht[now] = max (wht[now], n - siz[now]);
	if (wht[now] < mi)
	{
		mi = wht[now];
		ansnow = now;
	}
} 

int main ()
{
//	freopen ("centroid.in", "r", stdin);
//	freopen ("centroid.out", "w", stdout);
	clear ();
	cin >> n;

	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		addEdge (u, v);
		addEdge (v, u);
	}
	
	memset (wht, 0, sizeof (wht));
	ex[2] = 0;
	mi = 0x3f3f3f3f;
	
	cout << "to[2] = " << to[2] << endl; 
	dfs (to[2], -1);
	cout << ansnow << endl;
	
//	fclose (stdin);
//	fclose (stdout);
	return 0;
}

/*
5
1 2
2 3
2 4
3 5
*/

