/*
    未完结
    
    (直接摆烂
*/

#include <iostream>
#include <string>
#include <map>

using i64 = long long;
using ull = unsigned long long;

const int maxn = 3005;
const ull base = 233;

int n, Q;

std::string s;

std::unordered_map <ull, x> S;
std::unordered_map <ull, x> revS;

ull pow[maxn];
inline void cal () {
    pow[1] = 1;
    for (int i = 2; i <= n; i++) { pow[i] = pow[i - 1] * base; }
}

inline void initHash () {
    for (int i = 1; i <= n; i++) {
        ull hashNow = 0ull;

        for (int j = i; j <= n; j++) {
            hashNow = hashNow * base + s[j] - 'a';
            S[hashNow] ++;
        }
    }

    for (int i = n; i >= 1; i--) {
        ull hashNow = 0ull;

        for (int j = n; j >= i; j--) {
            hashNow = hashNow * base + s[j] - 'a';
            revS[hashNow] ++;
        }
    }
}

f

int main () {

    std::cin >> n >> Q;

    std::cin >> s; s = " " + s;

    cal ();

    while (Q--) {
        int l1, r1; std::cin >> l1 >> r1;

        int l2, r2; std::cin >> l2 >> r2;
    }

    return 0;
}