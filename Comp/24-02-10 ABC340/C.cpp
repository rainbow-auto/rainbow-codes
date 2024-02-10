#include <iostream>

using i64 = unsigned long long;

i64 res = 0;

void solve (i64 now) {
    if (now < 2) { return; }

    res += now;
    solve (now >> 1); solve ((now + 1ll) >> 1);
}

int main () {

    i64 x; std::cin >> x;

    solve (x);

    std::cout << res << "\n";

    return 0;
}