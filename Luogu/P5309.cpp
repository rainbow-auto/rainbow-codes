#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (int QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbendl std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

namespace IO {
const int MAXSIZE = 1 << 20;
char buf[MAXSIZE], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)

int read() {
  int x = 0, f = 1;
  char c = gc();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = gc();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
  return x * f;
}

char pbuf[1 << 20], *pp = pbuf;

void push(const char &c) {
  if (pp - pbuf == 1 << 20) fwrite(pbuf, 1, 1 << 20, stdout), pp = pbuf;
  *pp++ = c;
}

void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) push(sta[--top] + '0');
}
}  // namespace IO

using IO::read;
using IO::write;

const int maxn = 200005;
const int maxB = 505;
const int mod = 1e9 + 7;

int n, m;
int a[maxn];

int B, T = 144;

inline void madd(int& x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int bel[maxn], L[maxB], R[maxB], tot;
int sum[maxn];
void blocking() {
	B = std::pow(n, 0.5);
	rep (i, 1, n) {
		int bl = (i - 1) / B + 1;
		bel[i] = bl;
		if (not L[bl]) L[bl] = i; 
		R[bl] = i;
		madd(sum[bl], a[i]);
	}
}

int pre[maxB][maxB], suf[maxB][maxB];

void mdfy(int x, int y, int z) {
	if (x > T) {
		for (int i = y; i <= n; i += x) madd(a[i], z); 
		for (int i = y; i <= n; i += x) madd(sum[bel[i]], z);
	} else {
		rep (i, y, x) madd(pre[x][i], z);
		rep (i, 1, y) madd(suf[x][i], z);
	}
}

int qry(int l, int r) {
	int res = 0;
	if (bel[l] == bel[r]) {
		rep (i, l, r) madd(res, a[i]);
	} else {
		rep (i, l, R[bel[l]]) madd(res, a[i]);
		rep (i, L[bel[r]], r) madd(res, a[i]);
		rep (i, bel[l] + 1, bel[r] - 1) madd(res, sum[i]);
	}

	int lb, rb;
	rep (stp, 1, std::min(n, T)) { // step
		lb = (l - 1) / stp + 1;
		rb = (r - 1) / stp + 1;

		int ll = l - (lb - 1) * stp;
		int rr = r - (rb - 1) * stp;

		if (lb == rb) {
			madd(res, pre[stp][rr]);
			madd(res, mod - pre[stp][ll - 1]);
		} else {
			madd(res, suf[stp][ll]);
			madd(res, pre[stp][rr]);
			madd(res, 1ll * (rb - lb - 1) * pre[stp][stp] % mod);
		}
	}

	return res;
}

void solve() {
	n = read(); m = read();
	rep (i, 1, n) a[i] = read();

	blocking();

	while (m--) {
		// int op; std::cin >> op;
		int op = read();
		if (op == 1) {
			int x = read(), y = read(), z = read();
			// int x, y, z; std::cin >> x >> y >> z;
			mdfy(x, y, z);
		} else {
			int l = read(), r = read();
			// int l, r; std::cin >> l >> r;
			// std::cout << qry(l, r) << "\n";
			std::printf("%d\n", qry(l, r));
			// write(qry(l, r));
		}
	}
}

bool MemED;
int main() {
	// fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1;
	
	// int _; std::cin >> _;
	
	while (_--) {
		solve();
	}

	return 0;
}
