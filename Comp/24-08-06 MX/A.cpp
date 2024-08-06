#include <iostream>

using i64 = long long;

i64 exgcd (i64 a, i64 b, i64& x, i64& y) {
    if (not b) { x = 1; y = 0; return a; }
    i64 d = exgcd (b, a % b, y, x);
    y -= x * (a / b);
    return d;
}

i64 x, y, m, n, L;

int main () {

    std::cin >> x >> y >> m >> n >> L;

    i64 a = n - m;
    i64 b = L;
    i64 c = x - y;

    if (a < 0) { a = -a; c = -c; }

    i64 t0, k0; 
    i64 d = exgcd (a, b, t0, k0);
    
    if (c % d != 0) { std::cout << "Impossible\n"; return 0; }
    
    t0 *= c / d;
    k0 *= c / d;

    i64 tmin = (t0 % (b / d) + (b / d)) % (b / d);

    std::cout << tmin << "\n";

    return 0;
}