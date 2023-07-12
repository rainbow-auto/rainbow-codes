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

const int maxn = 505;
const int maxm = 2000005;

int n, f, d;

struct Edge{
	int u, v, pre;
	int flow;
};

Edge es[maxm];
int last[maxn], cnt;

inline void _addEdge (int u, int v, int cap)
{
	cnt ++;
	es[cnt].u = u;
	es[cnt].v = v;
	es[cnt].flow = cap;
	es[cnt].pre = last[u];
	last[u] = cnt;
}

inline void addEdge (int u, int v, int cap)
{
	_addEdge (u, v, cap);
	_addEdge (v, u, 0);
}

int S, T;
int dis[maxm];

bool bfs ()
{
	memset (dis, 0x3f, sizeof (dis));
	dis[S] = 0; queue<int> q; q.push(S);
	
	while (not q.empty ())
	{
		int now = q.front(); q.pop();
		for (int i = last[now]; i; i = es[i].pre)
		{
			int t = es[i].v;
		
			if (dis[t] == 0x3f3f3f3f and es[i].flow != 0) // û�б������һ���ʣ�� 
			{
				dis[t] = dis[now] + 1;
				q.push(t);				
			}			
		}
	}
	
	return dis[T] != 0x3f3f3f3f;
}

int cur[maxn]; // ���last, ��ǰ���Ż� 

int dfs (int now, int flow_now) // flow_now: ���ﵱǰ������� 
{
	if (flow_now == 0 or now == T) return flow_now; // û�������� or ���� ��ֱ�ӷ��� 
	
	int res = 0; // ��ǰ�������㵽t��������
	
	for (int &i = cur[now]; i; i = es[i].pre) // &i ��ǰ���Ż� 
	{
		int t = es[i].v;
		
		if (es[i].flow == 0 or dis[t] != dis[now] + 1) continue; // û�������� or t�Ĳ���now����һ��
		
		int flow_t = dfs (t, min(es[i].flow, flow_now)); // ��ǰ����t�������� ����ǰ������� �� now��t�ıߵ����� ����
		if (flow_t) // ������t
		{
			es[i].flow -= flow_t;     // now��t�ıߵ�������������flow_t
			es[i ^ 1].flow += flow_t; // ��Ӧ�ķ��ڱ�ҲҪ����flow_t
			res += flow_t;
			flow_now -= flow_t;
			if (flow_now == 0) return res; // û��������ֱ�ӷ��� 
		}
	} 
	
	return res; 
}

int dinic ()
{
	int res = 0;
		
	while (bfs ())
	{
		memcpy(cur, last, sizeof (cur));
		res += dfs (S, 0x3f3f3f3f); // Դ��ӵ�����޵�����
//		cout << "res += " << dfs (S, 0x3f3f3f3f) << endl;
	}
	
	return res;
} 

int main ()
{
	fastread
	
	cin >> n >> f >> d;
	
	cnt = 1; 
	S = 0;
	T = 2 * n + f + d + 1; // ��ţ���� ʳ��һ�� ����һ��
	
	// ��ͼ��ʽ: S -> ʳ�� -> ��ţ��   -> ��ţ��      ->        ����             -> T  
	//           0    1 ~ f  f+1 ~ f+n  f+n+1 ~ f+2*n   n + f + 1 ~ n + f + d   2 * n + f + d   
	for (int i = 1; i <= f; i++)
	{
		addEdge (S, i, 1); 	// S -> ʳ�� 
	}	
	
	for (int i = 1; i <= n; i++)  
	{
		addEdge (f + i, f + n + i, 1); // ��ţ�� -> ��ţ��	
	} 
	
	for (int i = 1; i <= d; i++)
	{
		addEdge (f + n * 2 + i, T, 1); // ���� -> T 		
	}
	
	for (int i = 1; i <= n; i++)
	{
		int x; 
		int fn, dn;
		
		cin >> fn >> dn;
		
		for (int j = 1; j <= fn; j++)
		{
			cin >> x;
			addEdge (x, f + i, 1);
		}	
		
		for (int j = 1; j <= dn; j++)
		{
			cin >> x;
			addEdge (f + n + i, x + f + n * 2, 1); 
		}
	}	
	
	cout << dinic () << endl;
			
	return 0;
}
