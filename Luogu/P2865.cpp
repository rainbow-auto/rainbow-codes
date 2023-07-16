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

const int maxn = 200005;

int n, m;

int to[maxn], pre[maxn], last[maxn];
int w[maxn];
int cnt;

inline void addEdge (int u, int v, int ww) {
	cnt ++;
	to[cnt] = v;
	w[cnt] = ww;
	pre[cnt] = last[u];
	last[u] = cnt;
}

struct Node {
	int u;
	int dis;
	
	friend bool operator < (Node a, Node b) {
		return a.dis > b.dis;
	}
};

int dis[maxn][2];

int dij () {
	memset (dis, 0x3f, sizeof (dis));
	dis[1][0] = 0;
	
	priority_queue<Node> q;
	
	q.push(Node{1, dis[1][0]});
		
	while (not q.empty()) {
		int u = q.top().u; q.pop();
		
		for (int i = last[u]; i; i = pre[i]) {
			int v = to[i];
			
			if (dis[v][0] >= dis[u][0] + w[i]) {
				dis[v][0] = dis[u][0] + w[i];
				q.push(Node{v, dis[v][0]});
			}
			else if (dis[v][1] > dis[u][0] + w[i]) {
				dis[v][1] = dis[u][0] + w[i];
				q.push(Node{v, dis[v][0]});
			} 
			
			if (dis[v][1] > dis[u][1] + w[i]) {
				dis[v][1] = dis[u][1] + w[i];
			}
		}		
	}
	
	return dis[n][1];
}

int main () {
	fastread
	
	while (cin >> n >> m) {
		memset (last, 0, sizeof (last));
		for (int i = 1; i <= m; i++) {
			int u, v, ww;
			cin >> u >> v >> ww;
			addEdge (u, v, ww);
			addEdge (v, u, ww);
		}
		
		cout << dij () << endl;
	}
	
	
	return 0;
}
