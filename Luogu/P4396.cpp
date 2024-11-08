#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

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
#define lookTime std::cerr << (double) (clock () - timeST) / CLOCKS_PER_SEC << "s used\n";
int timeST;
bool MemST;

const int maxn = 100005;
const int maxB = 350;

int n, m;
int a[maxn], mx;

int belong[maxn], tot;
int L[maxB], R[maxB];

namespace ValueBlocking {
	int belong[maxn], tot;
	int L[maxB], R[maxB];

	inline void init () {
		memset (L, 0x3f, sizeof (L));
		int B = (int) sqrt (mx) + 1;

		rep (i, 1, mx) {
			belong[i] = (i / B) + 1;
			L[belong[i]] = std::min (L[belong[i]], (int) i);
			R[belong[i]] = std::max (R[belong[i]], (int) i);
		}

		tot = belong[mx];
	}
};

int sum1[maxB][maxB][maxB]; // sum1[bl][br][x] : 在数列 bl 到 br 中, 值域块 x 的数的个数
int sum2[maxB][maxB][maxB]; // sum2[bl][br][x] : 在数列 bl 到 br 中, 值域块 x 中数的种类数
int sum3[maxB][maxn]; // sum3[b][x] : x 在数列前 b 块中出现了几次

int cnt[maxn];
inline void init () {
	memset (L, 0x3f, sizeof (L));
	int B = (int) sqrt (n) + 1;
	rep (i, 1, n) {
		belong[i] = (i / B) + 1;
		L[belong[i]] = std::min (L[belong[i]], (int) i);
		R[belong[i]] = std::max (R[belong[i]], (int) i);
	}

	tot = belong[n];

	ValueBlocking::init ();

	rep (l, 1, tot) {
		rep (r, l, tot) {
			rep (i, 1, ValueBlocking::tot) {
				sum1[l][r][i] = sum1[l][r - 1][i];
				sum2[l][r][i] = sum2[l][r - 1][i]; 
			}

			rep (i, L[r], R[r]) {
				if (not cnt[a[i]]) { sum2[l][r][ValueBlocking::belong[a[i]]] ++; }
				sum1[l][r][ValueBlocking::belong[a[i]]] ++;
				cnt[a[i]] ++;
			}
		}

		memset (cnt, 0, sizeof (cnt));
	}

	rep (b, 1, tot) {
		rep (i, L[b], R[b]) { cnt[a[i]] ++; }
		rep (i, 1, mx) { sum3[b][i] = sum3[b - 1][i] + cnt[i]; }
		rep (i, L[b], R[b]) { cnt[a[i]] --; }
	}
}

inline std::pair <int, int> query (int l, int r, int A, int B) {
	std::pair <int, int> res = { 0, 0 };

	if (belong[r] - belong[l] <= 1) {
		rep (i, l, r) {
			if (A <= a[i] and a[i] <= B) {
				res.first ++;
				if (not cnt[a[i]]) { res.second ++; }
			}
			cnt[a[i]] ++;
		}

		rep (i, l, r) { cnt[a[i]] --; }

		return res;
	}

	std::vector <int> col;

	rep (i, l, R[belong[l]]) {
		if (A <= a[i] and a[i] <= B) {
			res.first ++;
			if (not cnt[a[i]]) { col.push_back (a[i]); res.second ++; }
		}
		cnt[a[i]] ++;
	}

	rep (i, L[belong[r]], r) {
		if (A <= a[i] and a[i] <= B) {
			res.first ++;
			if (not cnt[a[i]]) { col.push_back (a[i]); res.second ++; }
		}
		cnt[a[i]] ++;
	}

	// clear
	rep (i, l, R[belong[l]]) { cnt[a[i]] --; }
	rep (i, L[belong[r]], r) { cnt[a[i]] --; }

	// get fullBlockRes
	std::pair <int, int> fullBlockRes = { 0, 0 };
	int bl = belong[l] + 1;
	int br = belong[r] - 1;

	if (ValueBlocking::belong[B] - ValueBlocking::belong[A] <= 1) {
		rep (i, A, B) {
			fullBlockRes.first += sum3[br][i] - sum3[bl - 1][i];
			fullBlockRes.second += sum3[br][i] - sum3[bl - 1][i] > 0;
		}
	} else {
		rep (i, A, ValueBlocking::R[ValueBlocking::belong[A]]) { 
			fullBlockRes.first += sum3[br][i] - sum3[bl - 1][i];
			fullBlockRes.second += sum3[br][i] - sum3[bl - 1][i] > 0;
		}

		rep (i, ValueBlocking::L[ValueBlocking::belong[B]], B) {
			fullBlockRes.first += sum3[br][i] - sum3[bl - 1][i];
			fullBlockRes.second += sum3[br][i] - sum3[bl - 1][i] > 0;
		}

		rep (i, ValueBlocking::belong[A] + 1, ValueBlocking::belong[B] - 1) {
			fullBlockRes.first += sum1[bl][br][i];
			fullBlockRes.second += sum2[bl][br][i];
		}
	}

	res.first += fullBlockRes.first;
	res.second += fullBlockRes.second;

	for (auto x : col) { if (sum3[br][x] - sum3[bl - 1][x] > 0) { res.second --; } }

	return res;
}

bool MemED;
int main () {
	fastread
	// timeST = clock ();
	// lookMem	

	timeST = clock ();

	std::cin >> n >> m;
	rep (i, 1, n) { std::cin >> a[i]; }

	mx = 100000;

	init ();

	rep (t, 1, m) {
		int l, r, A, B; std::cin >> l >> r >> A >> B;
		auto res = query (l, r, A, B);
		std::cout << res.first << " " << res.second << "\n";
	}

	return 0;
}
