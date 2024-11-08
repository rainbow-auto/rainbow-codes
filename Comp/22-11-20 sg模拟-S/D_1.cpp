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

int from[maxn], to[maxn], pre[maxn], last[maxn];
int cnt;
inline void addEdge (int u, int v)
{
	cnt ++;
	from[cnt] = u;
	to[cnt] = v;
	pre[cnt] = last[u];
	last[u] = cnt;
}

inline clear ()
{
	cnt = 0;
	memset (last, 0, sizeof (last));
}

int p1, p2;
int siz_now;
int ansnow;
int minn;

int siz[maxn];
int weight[maxn];
void dfs (int now, int fa)
{
	weight[now] = 0;
	siz[now] = 0;
	
	for (int i = last[now]; i; i = pre[i])
	{
		int t = to[i];
		if (t == fa) continue;
		if (t == p1 or t == p2) continue;
		dfs (t, now);
		siz[now] += siz[t];
		weight[now] = max (weight[now], siz[t]);
	}
	weight[now] = max (weight[now], n - siz[now]);
	if (minn > weight[now])
	{
		minn = weight[now];
		ansnow = now;
	}
}

int dfs2 (int now, int fa)
{
	int res = 1;
	for (int i = last[now]; i; i = pre[i])
	{
		int t = to[i];
		if (t == fa) continue;
		if (t == p1 or t == p2) continue;
		res += dfs2 (t, now);	
	}
	return res;	
}

int main ()
{
	cin >> T;
	while (T--)
	{
		clear ();
		cin >> n;
		for (int i = 1; i <= n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			addEdge (u, v);
			addEdge (v, u);
		}
		
		int ans = 0;
		for (int i = 1; i <= cnt; i++)
		{
			p1 = from[i], p2 = to[i];
			
			// from
			siz_now = dfs2 (p1, -1);
			memset (siz, 0, sizeof (siz));
			memset (weight, 0, sizeof (weight));
			ansnow = 0;
			minn = 0x3f3f3f3f;
			dfs (p1, -1);
			ans += ansnow;
//			cout << "## ans += " << ansnow << endl;
//			for (int j = last[ansnow]; j; j = pre[j])
//			{
//				int t = to[j];
//				if (weight[t] == minn) 
//				{
//					cout << "ans += " << t << endl;
//					ans += t;
//				}
//			}
						
			// to
			siz_now = dfs2 (p2, -1);
			memset (siz, 0, sizeof (siz));
			memset (weight, 0, sizeof (weight));
			ansnow = 0;
			minn = 0x3f3f3f3f;
			dfs (p2, -1);
			ans += ansnow;
//			cout << "## ans += " << ansnow << endl;
//			for (int j = last[ansnow]; j; j = pre[j])
//			{
//				int t = to[j];
//				if (weight[t] == minn) 
//				{
//					cout << "ans += " << t << endl;
//					ans += t;
//				}
//			}
		}
		
		cout << ans << endl;
	}
	return 0;
}

