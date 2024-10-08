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

const int maxn = 200005;
const int maxp = 25;

int n, k, m;

std::vector<int> lens;
bool a[maxn], b[maxn];
std::vector<int> pos;

std::bitset<maxn> vis;
std::queue<int> q;
void bfs(int S, std::array<int, maxn>& dis) {
	q.push(S); vis.reset();

	dis.fill(0x3f3f3f3f);
	dis[S] = 0; vis.set(S);

	while (not q.empty()) {
		int now = q.front(); q.pop();
		for (auto len : lens) {
			int t = now + len;
			
			if (t > n) continue;
			if (vis[t]) continue;
			vis.set(t);

			dis[t] = dis[now] + 1;
			q.push(t);
		}
		
		for (auto len : lens) {
			int t = now - len;
			if (t < 0) continue;
			if (vis[t]) continue;
			vis.set(t);

			dis[t] = dis[now] + 1;
			q.push(t);	
		}
	}
}

std::array<int, maxn> dis[maxp];

int dp[1 << 20 | 5];

void solve() {
	std::cin >> n >> k >> m;
	
	rep (i, 1, k) {
		int x; std::cin >> x;
		a[x] = true;
	}

	rep (i, 0, n) b[i] = a[i] ^ a[i + 1];
	rep (i, 0, n) if (b[i]) pos.push_back(i);

	rep (i, 1, m) {
		int l; std::cin >> l;
		lens.push_back(l);
	}

	rep (i, 0, (int) pos.size() - 1) bfs(pos[i], dis[i]);

	dp[0] = 0;
	rep (S, 1, (1 << pos.size()) - 1) {
		std::memset(dp + S, 0x3f, sizeof dp[S]);
		rep (i, 0, (int) pos.size() - 1) {
			if (not (S & (1 << i))) continue;
			rep (j, i + 1, (int) pos.size() - 1) {
				if (not (S & (1 << j))) continue;

				dp[S] = std::min(dp[S], dp[S - (1 << i) - (1 << j)] + dis[i][pos[j]]);
			}
		}
	}

	int res = dp[(1 << pos.size()) - 1];
	if (res == 0x3f3f3f3f) std::cout << "-1\n";
	else std::cout << res << "\n";
}

bool MemED;
int main() {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
