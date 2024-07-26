#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>

const int maxn = 200005;

int n;
int a[maxn];

inline int abs (int x) { return x > 0 ? x : -x; }

const long long inf = 1e9;

namespace Task1 {
    const int maxn = 25;
    
    int ans[maxn], w;

    int p[maxn];

    inline void solve () {
        for (int i = 1; i <= n; i++) { p[i] = i; }

        w = 0x3f3f3f3f;
        memset (ans, 0x3f, sizeof (ans));

        do {

            bool flag = true;
            for (int i = 1; i <= n - 1; i++) { flag &= ((a[p[i]] & 1) != (a[p[i + 1]] & 1)); }

            if (not flag) { continue; }
            
            int wnow = 0;
            for (int i = 1; i <= n; i++) { wnow += abs (i - p[i]); }

            if (wnow > w) { continue; }

            if (wnow == w) {
                for (int i = 1; i <= n; i++) {
                    if (a[p[i]] == a[ans[i]]) { continue; }
                    
                    if (a[p[i]] < a[ans[i]]) { memcpy (ans, p, sizeof (p)); break; }
                    else { break; }
                }
            } else {
                w = wnow;
                memcpy (ans, p, sizeof (p));
            }

        } while (std::next_permutation (p + 1, p + n + 1));

        for (int i = 1; i <= n; i++) { std::cout << a[ans[i]] << " "; } std::cout << "\n";
    }
}

namespace NetworkSimplex {
	struct Edge {
		int u, v;
		int pre;
		int flow;
		int cost;
	} es[maxm];

	int last[maxn], cnt = 1;

	inline void _addEdge (int u, int v, int cap, int cost) {
		es[++cnt] = Edge { u, v, last[u], cap, cost };
		last[u] = cnt;
	}

	inline void addEdge (int u, int v, int cap, int cost) {
		_addEdge (u, v, cap, cost);
		_addEdge (v, u, 0, -cost);
	}

	int fa[maxn], faEdge[maxn];
	int mark[maxn], curTime = 1;

	void initTree (int now) {
		for (int i = last[now]; i; i = es[i].pre) {
			int t = es[i].v;
			
			if (not es[i].flow) { continue; }
			
			if (mark[t]) { continue; }
			mark[t] = 1;
			
			fa[t] = now;
			faEdge[t] = i;
			
			initTree (t);
		}
	}

	int piCache[maxn];
	int pi (int now) {
		if (mark[now] == curTime) { return piCache[now]; }
		mark[now] = curTime; 
		return piCache[now] = es[faEdge[now]].cost + pi(fa[now]); 
	}

	inline long long pushFlow (int eid) {
		++curTime;
		
		int root = es[eid].u;
		while (root) { mark[root] = curTime; root = fa[root]; }

		int lca = es[eid].v;
		while (mark[lca] != curTime) { mark[lca] = curTime; lca = fa[lca]; }

		int minFlow = es[eid].flow;
		int delNode = 0;
		int flag = 2;
		std::vector <int> circle;

		for (int now = es[eid].u; now != lca; now = fa[now]) {
			int nowEdge = faEdge[now];
			circle.push_back (nowEdge);
			
			if (minFlow > es[nowEdge].flow) {
				minFlow = es[nowEdge].flow;
				flag = 0;
				delNode = now;
			}
		}

		for (int now = es[eid].v; now != lca; now = fa[now]) {
			int nowEdge = faEdge[now] ^ 1;
			circle.push_back (nowEdge);
			
			if (minFlow > es[nowEdge].flow) {
				minFlow = es[nowEdge].flow;
				flag = 1;
				delNode = now;
			}
		}
	
		circle.push_back (eid);

		long long cost = 0;
		for (auto now : circle) {
			es[now].flow -= minFlow;
			es[now ^ 1].flow += minFlow;
			cost += minFlow * es[now].cost;
		}

		if (flag == 2) { return cost; }

		eid = eid ^ flag;
		int u = es[eid].u;
		int v = es[eid].v;

		int lastNode = v;
		int lastEdge = eid; 
		int nextNode = 0; 
		for (int now = u; lastNode != delNode; now = nextNode) {
			nextNode = fa[now];
			mark[now] --; 

			lastEdge ^= 1;
			swap (lastEdge, faEdge[now]);
			
			fa[now] = lastNode;
			lastNode = now;		
		}

		return cost;
	}

	struct MCMF {
		int minCost, maxFlow;
	};

	inline MCMF simplex (int S, int T) {
		addEdge (T, S, inf, -inf);
		
		initTree (T); 
		mark[T] = ++curTime;
		fa[T] = 0;

		long long cost = 0;
		while (true) {
			bool flag = false;
			for (int i = 2; i <= cnt; i++) {
				if (es[i].flow and es[i].cost + pi(es[i].u) - pi(es[i].v) < 0) {
					flag = true;
					cost += pushFlow (i);
				}
			}

			if (not flag) { break; }
		}

		int maxFlow = es[cnt].flow; 
		int minCost = int ((long long) es[cnt].flow * inf + cost);  
		return MCMF { minCost, maxFlow };
	}

	inline void clear () {
		memset (mark, 0, sizeof(mark)); curTime = 1;
		memset (piCache, 0, sizeof(piCache));
		memset (last, 0, sizeof(last)); cnt = 1;
	}
}

namespace Task2 {
    int cnt0 = 0;
    int cnt1 = 0;

    inline void solve (bool start) {
        NetworkSimplex::clear ();

        int tot = 0;

        for (int i = 1; i <= n; i++) { 
            id[i] = ++tot;
            NetworkSimplex::addEdge (S, id[i], 1, 0); 
        }

        for (int i = 1; i <= n; i++) { 
            NetworkSimplex::addEdge (S,) 
        }

        for (int i = 1; i <= n; i++) {
            if (a[i] & 1) { NetworkSimplex::addEdge () }
        }
    }

    inline void solve () {
        if (n & 1) {
            if (cnt0 > cnt1) { solve (0); }
            else { solve (1); }
        } else {
            solve (0); solve (1);
        }
    }
}

int main () {

    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    Task1::solve ();

    return 0;
}