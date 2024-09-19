#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define dbg(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#define db std::cerr

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

template <int MOD>
struct modint {
    int val;
    static int norm(const int& x) { return x < 0 ? x + MOD : x; }
    static constexpr int get_mod() { return MOD; }
    modint() : val(0) {}
    modint(const int& m) : val(norm(m)) {}
    modint(const long long& m) : val(norm(m % MOD)) {}
    modint operator-() const { return modint(norm(-val)); }
    bool operator==(const modint& o) { return val == o.val; }
    bool operator<(const modint& o) { return val < o.val; }
    modint& operator+=(const modint& o) { return val = (1ll * val + o.val) % MOD, *this; }
    modint& operator-=(const modint& o) { return val = norm(1ll * val - o.val), *this; }
    modint& operator*=(const modint& o) { return val = static_cast<int>(1ll * val * o.val % MOD), *this; }
    modint& operator/=(const modint& o) { return *this *= o.inv(); }
    modint& operator^=(const modint& o) { return val ^= o.val, *this; }
    modint operator-(const modint& o) const { return modint(*this) -= o; }
    modint operator+(const modint& o) const { return modint(*this) += o; }
    modint operator*(const modint& o) const { return modint(*this) *= o; }
    modint operator/(const modint& o) const { return modint(*this) /= o; }
    modint operator^(const modint& o) const { return modint(*this) ^= o; }
    bool operator!=(const modint& o) { return val != o.val; }
    modint operator>>(const modint& o) const { return modint(*this) >>= o; }
    modint operator<<(const modint& o) const { return modint(*this) <<= o; }
	
	friend std::istream& operator>>(std::istream& is, modint& a) {
        long long v;
        return is >> v, a.val = norm(v % MOD), is;
    }
    friend std::ostream& operator<<(std::ostream& os, const modint& a) { return os << a.val; }
    
	friend std::string to_string(const modint& a) { return std::to_string(a.val); }
   
    template <typename T>
    friend modint ksm(const modint a, const T& b) {
        assert(b >= 0);
        modint x = a, res = 1;
        for (T p = b; p; x *= x, p >>= 1)
            if (p & 1) res *= x;
        return res;
    }
    modint inv() const {
        return ksm(*this,MOD-2);
    }
};

using mint = modint<(int) 1e9 + 7>;

const int maxk = 25;
const int maxn = 1005;

int n, k;
int a[maxn];
mint f[maxn][maxn];

mint fac[maxn], ifac[maxn];
inline void init (int R) {
	fac[0] = (mint) 1;
	rep (i, 1, R) { fac[i] = fac[i - 1] * i; }
	ifac[R] = (mint) 1 / fac[R];
	per (i, R - 1, 0) { ifac[i] = ifac[i + 1] * (i + 1); }
}

inline mint choose (int x, int y) {
	if (x < y) { return 0; }
	return fac[x] * ifac[y] * ifac[x - y];
}

inline void solve () {
	std::cin >> n >> k;
	rep (i, 1, k) { std::cin >> a[i]; }

	init (n);

	f[0][0] = 1;
	rep (i, 1, k) {
		rep (j, 0, n) {
			rep (t, 0, std::min ((int) j, a[i])) {
				f[i][j] += f[i - 1][j - t] * choose (n - (j - t), t) * choose (n - t, a[i] - t);
			}
		}
	}

	std::cout << f[k][n] << "\n";
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	int _ = 1; 
	while (_--) { solve (); }

	return 0;
}
