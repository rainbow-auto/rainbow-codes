#include <iostream>

using i64 = long long;

struct Num {
    int up, dw; // 分子 | 分母

    inline void show () {
        std::cerr << up << " / " << dw << "\n";
    }
};

// calc: cnt (t, k)
// s.t. {
// a1 + d1 * k + 2 * t * (a2 + d2 * k) <= n
// a2 + d2 * k <= m
// }

inline i64 calc (i64 a1, i64 d1, i64 a2, i64 d2, i64 n, i64 m) {
    i64 res = 0;
    
    // case 1 : t == 0
    // a1 + k * d1 <= n
    // a2 + k * d2 <= m
    res += std::min (std::max (((n - a1) / d1), 0ll), std::max (((m - a2) / d2), 0ll));

    // case 2 : t != 0
    for (i64 t = 1; ; t++) {
        i64 lim1 = (n - a1 - 2 * t * a2) / (d1 + 2 * d2 * t);
        i64 lim2 = (m - a2) / d2;

        if (lim1 <= 0 or lim2 <= 0) { break; }

        res += std::min (lim1, lim2);
    }

    return res;
}

inline i64 solve (i64 n, i64 m) {
    i64 res = (n >> 1) + (m >> 1);

    Num fst = Num { 1, 2 };
    Num sec = Num { 1, 4 };

    while (true) {
        fst.up = fst.dw * 2ll + fst.up;
        sec.up = sec.dw * 2ll + sec.up;

        i64 delta = 0;

        i64 d1 = sec.up - fst.up;
        i64 d2 = sec.dw - fst.dw;

        i64 a1 = fst.up - d1;
        i64 a2 = fst.dw - d2;

        delta += calc (a1, d1, a2, d2, n, m);
        delta += calc (a1, d1, a2, d2, m, n);

        std::swap (fst.up, fst.dw);
        std::swap (sec.up, sec.dw);

        if (not delta) { break; }

        res += delta;
    }

    return res;
}

int main () {

    // freopen ("number.in", "r", stdin);
    // freopen ("number.out", "w", stdout);

    i64 n, m; std::cin >> n >> m;

    std::cout << solve (n, m) << "\n";

    return 0;
}