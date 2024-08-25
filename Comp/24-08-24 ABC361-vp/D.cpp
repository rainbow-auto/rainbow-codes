#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#pragma GCC optimize(2)

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
bool MemST;

int n;
std::string st, ed;

struct Node {
	std::string s;
	int dis;
};

std::set <std::string> vis;

inline int bfs () {
	vis.insert (st);
	std::queue <Node> q; q.push (Node { st, 0 });

	while (not q.empty ()) {
		auto now = q.front (); q.pop ();

		if (now.s == ed) { return now.dis; }

		int pos = 0;
		for (int i = 1; i <= n + 1; i++) {
			if (now.s[i] == '.' and now.s[i + 1] == '.') { pos = i; break; }
		} 

		for (int i = 1; i <= n + 1; i++) {
			if (now.s[i] != '.' and now.s[i + 1] != '.') {
				std::string ns = now.s;
				ns[pos] = now.s[i];
				ns[pos + 1] = now.s[i + 1];
				ns[i] = '.'; ns[i + 1] = '.';

				if (vis.count (ns)) { continue; }

				q.push (Node { ns, now.dis + 1 });
			}
		}
	}

	return -1;
}

bool MemED;
int main () {
	fastread
	// lookMem	

	std::cin >> n;
	std::cin >> st; st = " " + st + "..";
	std::cin >> ed; ed = " " + ed + "..";

	std::cout << bfs () << "\n";

	return 0;
}
