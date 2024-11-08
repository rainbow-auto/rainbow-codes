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
#define endl '\n'

using namespace std;

const int maxn = 1405;
const int maxm = 1000005; // 982800

namespace Net {
	struct Edge {
		int u, v;
		int pre;
		int flow;
	} es[maxm];

	int last[maxn], cur[maxn], cnt;

	inline void _addEdge (int u, int v, int cap) {
		es[++cnt] = Edge { u, v, last[u], cap };
		last[u] = cnt;
	}

	inline void addEdge (int u, int v, int cap) {
		_addEdge (u, v, cap);
		_addEdge (v, u, 0);
	}

	int S, T;

	int tot;
	inline int newNode () { return ++tot; }

	int dep[maxn];
	inline bool bfs (int _s, int _t) {
		queue<int> q; q.push (_s);
		memset (dep, 0, sizeof (dep)); dep[_s] = 1;

		while (not q.empty ()) {
			int now = q.front (); q.pop ();
			
			for (int i = last[now]; i; i = es[i].pre) {
				int t = es[i].v;

				if (not es[i].flow) { continue; }
				if (dep[t]) { continue; }

				dep[t] = dep[now] + 1;
				q.push (t);
				
				if (t == _t) { return true; }
			}
		}

		return dep[_t];
	}

	int dfs (int now, int now_flow) {
		if (now == T or not now_flow) { return now_flow; }

		int res = 0;
		for (int &i = cur[now]; i; i = es[i].pre) {
			int t = es[i].v;

			if (not es[i].flow) { continue; }
			if (dep[t] != dep[now] + 1) { continue; }

			int t_flow = dfs (t, min (es[i].flow, now_flow));
			if (t_flow) {
				es[i].flow -= t_flow;
				es[i ^ 1].flow += t_flow;
				now_flow -= t_flow;
				res += t_flow;

				if (not now_flow) { break; } 
			}
		}

		return res;
	}

	int dinic (int _s, int _t) {
		S = _s, T = _t;

		int maxFlow = 0;
		while (bfs (S, T)) {
			memcpy (cur, last, sizeof (last));
			maxFlow += dfs (S, 0x3f3f3f3f);
		}
		
		return maxFlow;
	}

	inline void clear () {
		memset (last, 0, sizeof (last)); 
		cnt = 1; tot = 0;
	}

	inline void recovery () {
		for (int i = 2; i <= cnt; i += 2) {
			es[i].flow += es[i ^ 1].flow;
			es[i ^ 1].flow = 0;
		}
	}
}

int n;

int a[maxn], b[maxn];

struct C {
	int pos, val;

	friend bool operator < (C x, C y) {
		return x.val < y.val;
	}
} c[maxn];

int dp[maxn];
inline int DynamicProgramming () {
	int maxLen = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i]) { dp[i] = max (dp[i], dp[j] + 1); }
		}
		maxLen = max (dp[i], maxLen);
	}

	return maxLen;
}

struct Node {
	int x, y;
	int cnt;
} id[maxn];

inline auto buildGraph (int maxLen) {
	for (int i = 1; i <= n; i++) { id[i].x = Net::newNode (); }
	for (int i = 1; i <= n; i++) { id[i].y = Net::newNode (); }
	int S = Net::newNode ();
	int T = Net::newNode ();

	for (int i = 1; i <= n; i++) { id[i].cnt = Net::cnt + 1; Net::addEdge (id[i].x, id[i].y, b[i]); }
	for (int i = 1; i <= n; i++) { if (dp[i] == 1) { Net::addEdge (S, id[i].x, 0x3f3f3f3f); } }
	for (int i = 1; i <= n; i++) { if (dp[i] == maxLen) { Net::addEdge (id[i].y, T, 0x3f3f3f3f); } }

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] and dp[i] == dp[j] + 1) {
				Net::addEdge (id[j].y, id[i].x, 0x3f3f3f3f);
			}
		}
	}

	return pair <int, int> { S, T };
}

inline void read (int &x) {
	int flag = 1; x = 0;
	char ch = getchar ();
	while (not isdigit (ch)) { ch = getchar (); }
	while (isdigit (ch)) { x = (x << 1) + (x << 3) + ch - '0'; ch = getchar (); }
} 

void write (int x) {
	if (x < 10) { putchar (x + '0'); }
	else { write (x / 10); putchar ((x % 10) + '0'); }
}

int main () {
	// fastread
	
	int T; read(T);
	while (T--) {
		Net::clear ();

		read(n);
		for (int i = 1; i <= n; i++) { read(a[i]); }	
		for (int i = 1; i <= n; i++) { read(b[i]); }	
		for (int i = 1; i <= n; i++) { read(c[i].val); c[i].pos = i; }

		int maxLen = DynamicProgramming ();

		auto st = buildGraph (maxLen);
		int ans1 = Net::dinic (st.first, st.second);   

		sort (c + 1, c + n + 1);
		
		vector <int> del;
		for (int i = 1; i <= n; i++) {
			int now = c[i].pos;
			int nowEdge = id[now].cnt;
			if (not Net::bfs (id[now].x, id[now].y)) {
			// if (Net::dep[id[now].x] ^ Net::dep[id[now].y]) {
				del.push_back (now);
				Net::es[nowEdge].flow = Net::es[nowEdge ^ 1].flow = 0;
				Net::recovery ();
				Net::dinic (st.first, st.second);
			}
		}
		sort (del.begin (), del.end ());

		// cout << ans1 << " " << del.size () << endl;
		// for (auto now : del) { cout << now << " "; } cout << endl;
		write (ans1); putchar (' '); write (del.size()); putchar (endl);
		for (auto now : del) { write (now); putchar (' '); } putchar (endl); 
	}

	return 0;
}
