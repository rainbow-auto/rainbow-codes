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

const int maxn = 5005;
const int maxm = 100005;
const long long inf = 1e9;

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

	int fa[maxn], faEdge[maxn]; // fa[u] : u的父亲 | faEdge[u] : 父亲指向u的边
	int mark[maxn], curTime = 1; // mark[u] : 节点u的时间戳 | curTime : 当前时间

	// 先找出基解 (随便找一棵生成树)
	// 此时mark的作用是标记是否访问过
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

	int piCache[maxn]; // 缓存一下pi优化
	int pi (int now) { // 当前节点到根节点的代价和
		if (mark[now] == curTime) { return piCache[now]; } // 当前节点的时间戳是当前时间 (piCache里的东西没有过时), 直接返回
		mark[now] = curTime; // 当前点经过更新已经是最新的了
		return piCache[now] = es[faEdge[now]].cost + pi(fa[now]); // 当前点的pi是从根节点到父亲的代价 + 父亲到当前点的代价
	}

	inline long long pushFlow (int eid) { // 沿着给定非树边的编号eid形成的环推流
		++curTime; // 时间戳增加
		
		// 找根
		int root = es[eid].u;
		while (root) { mark[root] = curTime; root = fa[root]; } // 向上跳并在跳的路径上打标记

		// 找lca
		int lca = es[eid].v;
		while (mark[lca] != curTime) { mark[lca] = curTime; lca = fa[lca]; } // 向上跳, 一直跳到被标记过 (也就是说要跳到在u到根的路径上),, 显然第一个跳到的点是lca

		// 找出基的边 (流量最小的边)

		int minFlow = es[eid].flow; // 能流的流量 (最小的流量)
		int delNode = 0; // 被删去的边的对应点
		int flag = 2; // flag = 2 : 没找到 (当前边就是) | 0 : 在lca到u的路径上 | 1 : 在v到lca的路径上
		vector <int> circle; // 存环上的边

		// 从u向上找lca往u方向的流量最小的边
		for (int now = es[eid].u; now != lca; now = fa[now]) {
			int nowEdge = faEdge[now]; // 因为是lca往u方向流所以是u的父亲到u的边
			circle.push_back (nowEdge);
			
			if (minFlow > es[nowEdge].flow) {
				minFlow = es[nowEdge].flow;
				flag = 0;
				delNode = now;
			}
		}

		// 从v想上找v往lca方向的流量最小的边
		for (int now = es[eid].v; now != lca; now = fa[now]) {
			int nowEdge = faEdge[now] ^ 1; // 因为是v往lca方向流所以是v到父亲的边
			circle.push_back (nowEdge);
			
			if (minFlow > es[nowEdge].flow) {
				minFlow = es[nowEdge].flow;
				flag = 1;
				delNode = now;
			}
		}
	
		circle.push_back (eid);

		// 给环上每个边增加流量并统计费用
		long long cost = 0;
		for (auto now : circle) {
			es[now].flow -= minFlow;
			es[now ^ 1].flow += minFlow;
			cost += minFlow * es[now].cost;
		}

		if (flag == 2) { return cost; } // 最小边是当前边, 不许要改变树的结构

		// 改变树的结构 (加入入基边, 删除出基边)
		// 实际上就是翻转树的结构 (此处我们直接暴力翻转)

		// 如果最小边是在lca到u的路径上, 我们实际上要对v->u->delNode的路径进行更新; 
		// 如果最小边是在v到lca的路径上, 我们实际上要对u->v->delNode的路径进行更新
		// 这里有一个trick
		// 我们发现, 在第一种情况里的u->delNode和第二种情况里v->delNode的路径中, 我们原有的faEdge[x]都是从我们要跳到的点, 指向当前点x
		// 如果我们能统一边的方向(从我们要跳到的点指向当前点), 翻转整条链的操作就会变得非常好处理
		// 然后我们又发现
		// 第一种情况里u->v的这条边恰好满足从我们要跳到的点u到我们当前的点v这一条件
		// 第二种情况正好相反
		// 所以第二种情况下, 我们先对我们要加入的这条边u->v翻转一下, 取他的反向边v->u
		// 这样就可以统一处理了

		eid = eid ^ flag; // 所以我们直接异或上flag (如果在lca到u的路径上, flag就等于0, 异或上0等于没有异或)
		int u = es[eid].u;
		int v = es[eid].v;

		int lastNode = v; // 上一个操作的点
		int lastEdge = eid; // 上一个边
		int nextNode = 0; // 下一个点
		for (int now = u; lastNode != delNode; now = nextNode) {
			nextNode = fa[now];
			mark[now] --; // 信息过期, 时间戳--

			lastEdge ^= 1; // 将上一条边翻转
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

		// 最后加上的边反向边 (S -> T) 的flow就是我们的最大流
		// (因为我们这条边加的意义是使得任意S到T的流都可以与它形成负环, 所以每次推流的时候都会把增加的流量加到它上面去)
		int maxFlow = es[cnt].flow; 
		int minCost = int ((long long) es[cnt].flow * inf + cost); // 需要加上 es[cnt].flow * inf 抵消掉一开始那条边的费用  
		return MCMF { minCost, maxFlow };
	}

	inline void clear () {
		memset (mark, 0, sizeof(mark)); curTime = 1;
		memset (piCache, 0, sizeof(piCache));
		memset (last, 0, sizeof(last)); cnt = 1;
	}
}

int main () {
	fastread
	
	NetworkSimplex::clear ();

	int n, m, S, T; cin >> n >> m >> S >> T;

	for (int i = 1; i <= m; i++) {
		int u, v, cap, cost; cin >> u >> v >> cap >> cost;
		NetworkSimplex::addEdge (u, v, cap, cost);
	}

	auto res = NetworkSimplex::simplex (S, T);

	cout << res.maxFlow << " " << res.minCost << endl;

	return 0;
}
