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
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const i64 mod = 1e9 + 7;
const i64 base = 2;
namespace Math {
    inline i64 ksm (i64 a, i64 b) {
        i64 res = 1;
        a %= mod;
        while (b) {
            if (b & 1) { (res *= a) %= mod; }
            (a *= a) %= mod; b >>= 1;
        }
        return res;
    } 

    inline i64 inv (i64 x) { return ksm (x, mod - 2); }

    inline i64 calc (i64 x, i64 k, i64 len) {
        if (k == 0) { return len * ksm (base, x) % mod; }
        i64 p = ksm (base, k);
        return ksm (base, x) * (ksm (p, len) - 1) % mod * inv (p - 1) % mod;
    }
}

using namespace Math;

const int maxn = 300005;

int n;
struct Node {
    i64 sum;
    i64 mn;

    Node () { sum = 0; mn = 1e18; }
} tr[maxn << 3];

inline void pushUp (int now) { 
    tr[now].sum = (tr[now << 1].sum + tr[now << 1 | 1].sum) % mod; 
    tr[now].mn = std::min (tr[now << 1].mn, tr[now << 1 | 1].mn);
}

void modify (int now, int l, int r, int pos, i64 val) {
    if (l == r) { tr[now].sum = ksm (base, val); tr[now].mn = val; return; }
    int mid = (l + r) >> 1;
    if (pos <= mid) { modify (now << 1, l, mid, pos, val); }
    else { modify (now << 1 | 1, mid + 1, r, pos, val); }
    pushUp (now);
}

i64 querySum (int now, int l, int r, int L, int R) {
    if (L <= l and r <= R) { return tr[now].sum; }
    i64 res = 0;
    int mid = (l + r) >> 1;
    if (L <= mid) { (res += querySum (now << 1, l, mid, L, R)) %= mod; }
    if (R > mid) { (res += querySum (now << 1 | 1, mid + 1, r, L, R)) %= mod; }
    return res;
}

i64 queryMin (int now, int l, int r, int L, int R) {
    if (L <= l and r <= R) { return tr[now].mn; }
    i64 res = 1e18;
    int mid = (l + r) >> 1;
    if (L <= mid) { res = std::min (res, queryMin (now << 1, l, mid, L, R)); }
    if (R > mid) { res = std::min (res, queryMin (now << 1 | 1, mid + 1, r, L, R)); }
    return res;
}

bool chk (int l, int r, i64 k) {
    i64 x = queryMin (1, 1, n, l, r);
    return calc (x, k, r - l + 1) == querySum (1, 1, n, l, r);
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

    int q; 
    std::cin >> n >> q;

    rep (i, 1, n) { i64 x; std::cin >> x; modify (1, 1, n, i, x); }

    i64 cnt = 0;
    while (q--) {
        int op; std::cin >> op;
        if (op == 1) {
            int x, y; std::cin >> x >> y;
            x ^= cnt; y ^= cnt;
            modify (1, 1, n, x, y);
        } else {
            int l, r; std::cin >> l >> r;
            l ^= cnt; r ^= cnt;
            if (l > r) { std::swap (l, r); }
            i64 k; std::cin >> k;
            k ^= cnt;

            if (chk (l, r, k)) { std::cout << "Yes\n"; cnt ++; }        
            else { std::cout << "No\n"; }
        }
    }

	return 0;
}
