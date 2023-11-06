#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 20005;
int n, p;

int to[maxn], pre[maxn], last[maxn];
int w[maxn];
int cnt;

int in[maxn];
int out[maxn];

inline void addEdge (int u, int v, int ww)
{
	in[v] ++;
	out[u] ++;
	cnt ++;
	to[cnt] = v;
	pre[cnt] = last[u];
	last[u] = cnt;
	w[cnt] = ww;
}

int c[maxn];
int u[maxn];

bool is_in0[maxn];
void tuopu ()
{
	queue <int> q; 
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 0)
		{
			q.push (i);
			is_in0[i] = true;
		}
	}
	while (not q.empty())
	{
		int now = q.front ();
		q.pop ();
		for (int i = last[now]; i; i = pre[i])
		{
			int t = to[i];
			in[t] --;
			if (c[now] > 0)
			{
				c[t] += w[i] * c[now];
			}
			if (not in[t])
			{
				q.push(t);
			}
		}
	}
}


int main ()
{
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i] >> u[i];
		if (c[i] == 0)
		{
			c[i] -= u[i];
		}
	}
	
	for (int i = 1; i <= p; i++)
	{
		int a, b, ww;
		cin >> a >> b >> ww;
		addEdge (a, b, ww);
	}
	
	tuopu ();
	
	bool flag = 0;
	for (int i = 1; i <= n; i++)
	{
//		if (is_in0[i]) continue;
		if (c[i] > 0 and out[i] == 0)
		{
			cout << i << " " << c[i] << endl;
			flag = true;
		}
	}
	if (not flag) cout << "NULL" << endl;	
		
	return 0;
}
