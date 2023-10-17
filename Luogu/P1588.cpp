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

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 200005;

int n, k;

namespace Solution {
	struct Node {
		int pos;
		int dis;
	};

	bool vis[maxn];
	inline void bfs () {
		memset (vis, 0, sizeof (vis));

		std::queue <Node> q; q.push (Node{ n, 0 });

		while (not q.empty ()) {
			Node now = q.front (); q.pop ();

			if (now.pos == k) { std::cout << now.dis << "\n"; break; }

			if (now.pos + 1 < maxn and not vis[now.pos + 1]) { vis[now.pos + 1] = true; q.push (Node { now.pos + 1, now.dis + 1 }); }
			if (now.pos - 1 >= 0 and not vis[now.pos - 1]) { vis[now.pos - 1] = true; q.push (Node { now.pos - 1, now.dis + 1 }); }
			if (now.pos * 2 < maxn and not vis[now.pos * 2]) { vis[now.pos * 2] = true; q.push (Node { now.pos * 2, now.dis + 1 }); }
		}
	}
}

int main () {
	fastread

	int T; std::cin >> T;

	while (T--) {
		std::cin >> n >> k;
		Solution::bfs ();
	}

	return 0;
}
