#include <iostream>
#include <algorithm>
#include <vector>

using i64 = unsigned long long;

const int maxn = 20;

i64 n;

i64 pw10[maxn];

int main () {

    std::cin >> n;

    pw10[0] = 1;
    for (int i = 1; i <= 18; i++) { pw10[i] = pw10[i] * 10ll; }

    i64 now = 0;
    i64 side = 0;

    int len = 0;
    while (true) {
        len ++;

        i64 curr = 0;
        if (len & 1) {
            if (len == 1) { curr = 9ll; side = 0; }
            else { curr = 10ll * 9ll * pw10[(len >> 1) - 1]; side = 9ll * pw10[(len >> 1) - 1]; }
        } else {
            curr = 9ll * pw10[(len >> 1) - 1];
            side = pw10[(len >> 1) - 1];
        }

        if (now + curr >= n) { break; }
        now += curr;
    }

    if (side == 0) { std::cout << 0 << "\n"; return 0; }

    i64 mid = (n - now) / side;

    i64 r = (n - now) % side;

    std::vector<int> l;
    while (r) { l.push_back (r % 10); r /= 10ll; }
    std::reverse (l.begin (), l.end ());

    for (auto x : l) { std::cout << x; }
    std::cout << mid;
    std::cout << r;
    
    return 0;
}