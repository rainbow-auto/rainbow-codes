#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;
// #define MultiTask lovely_fairytale

const int maxn = 505;

int n, m;
char a[maxn][maxn];

struct Status {
	int x, y;
	int p; // 0: 竖直 | 1: 横向水平 | 2: 纵向水平
	int stp;

	friend bool operator == (Status a, Status b) {
		return a.x == b.x and a.y == b.y and a.p == b.p;
	}
};

inline bool chk(Status now) {
	if (now.x < 1 or now.x > n) return false;
	if (now.y < 1 or now.y > m) return false;

	if (a[now.x][now.y] == '#') return false;

	if (now.p == 1) if (a[now.x][now.y + 1] == '#') return false; 
	if (now.p == 2) if (a[now.x + 1][now.y] == '#') return false;

	if (a[now.x][now.y] == 'E' and now.p == 0) return false;

	return true;
}

inline void push(Status nxt, std::queue<Status> &q) {
	if (not chk(nxt)) return;
	q.push(nxt);
}

bool vis[maxn][maxn][3];

inline int bfs(Status st, Status ed) {
	std::memset(vis, 0, sizeof vis);

	std::queue<Status> q;
	q.push(st);

	while (not q.empty()) {
		auto now = q.front(); q.pop();
		if (now == ed) return now.stp;

		if (vis[now.x][now.y][now.p]) continue;
		vis[now.x][now.y][now.p] = true;

		if (now.p == 0) {
			push(Status { now.x, now.y - 2, 1, now.stp + 1 }, q);
			push(Status { now.x, now.y + 1, 1, now.stp + 1 }, q);
			push(Status { now.x - 2, now.y, 2, now.stp + 1 }, q);
			push(Status { now.x + 1, now.y, 2, now.stp + 1 }, q);
		} else if (now.p == 1) {
			push(Status { now.x, now.y - 1, 0, now.stp + 1 }, q);
			push(Status { now.x, now.y + 2, 0, now.stp + 1 }, q);
			push(Status { now.x - 1, now.y, 1, now.stp + 1 }, q);
			push(Status { now.x + 1, now.y, 1, now.stp + 1 }, q);
		} else if (now.p == 2) {
			push(Status { now.x, now.y - 1, 2, now.stp + 1 }, q);
			push(Status { now.x, now.y + 1, 2, now.stp + 1 }, q);
			push(Status { now.x - 1, now.y, 0, now.stp + 1 }, q);
			push(Status { now.x + 2, now.y, 0, now.stp + 1 }, q);
		}
	}
	return -1;
}

inline Status get_st() {
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (a[i][j] != 'X') continue;
			Status st;
			
			st.p = 0;
			if (a[i][j + 1] == 'X') st.p = 1;
			if (a[i + 1][j] == 'X') st.p = 2;

			st.x = i; st.y = j;
			st.stp = 0;

			return st;
		}
	}
}

inline Status get_ed() {
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (a[i][j] == 'O') return Status { i, j, 0, 0 };
		}
	}
}

inline bool solve() {
	std::cin >> n >> m;

	if (not n or not m) return false;

	std::memset(a, 0, sizeof a);
	rep (i, 0, n + 1) rep (j, 1, m + 1) a[i][j] = '#';

	rep (i, 1, n) {
		rep (j, 1, m) {
			std::cin >> a[i][j];
		}
	}

	Status st = get_st();
	Status ed = get_ed();

	int res = bfs(st, ed);

	if (~res) std::cout << res << "\n";
	else std::cout << "Impossible\n";

	return true;
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

#ifndef MultiTask
	int _ = 1;
#else
	int _; std::cin >> _;
#endif
	
	while (solve());

	return 0;
}
