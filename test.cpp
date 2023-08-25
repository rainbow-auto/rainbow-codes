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
		vector <int> circle; 

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
		addEdge (T, S, inf, -inf); // 加这条辅助边保证最大流
		
		initTree (T); // 寻找基解
		mark[T] = ++curTime;
		fa[T] = 0; // 钦定T是根

		long long cost = 0; // 由于一开始加了一条费用为-inf的边, 费用可能很大, 最好开long long
		while (true) {
			bool flag = false;
			for (int i = 2; i <= cnt; i++) {
				if (es[i].flow and es[i].cost + pi(es[i].u) - pi(es[i].v) < 0) { // 寻找可以形成负环的边
					flag = true;
					cost += pushFlow (i);
				}
			}

			if (not flag) { break; } // 没有找到可以形成负环推流的边, 停止
		}

		int maxFlow = es[cnt].flow; 
		int minCost = (long long) es[cnt].flow * inf + cost; // 需要加上 es[cnt].flow * inf 抵消掉一开始那条边的费用  
		return MCMF { minCost, maxFlow };
	}

	inline void clear () {
		memset (mark, 0, sizeof(mark)); curTime = 1;
		memset (piCache, 0, sizeof(piCache));
		memset (last, 0, sizeof(last)); cnt = 1;
	}
}
