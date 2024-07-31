#include <iostream>
#include <algorithm>

using i64 = long long;

int binsearch(int P[], int L, int R, int x) {
    if(L>R)
        return 0;
    int MID = (L + R) / 2;
    if(P[MID] == x || L == R)
        return P[MID];
    if(P[MID] > x)
        return P[MID] + binsearch(P, L, MID - 1, x);
    if(P[MID] < x)
        return P[MID] + binsearch(P, MID + 1, R, x);
}

const int maxn = 15;
const int mod = 1e9 + 7;

int n, m;
int a[maxn];

int p[maxn];

int main () {

    freopen ("binary.in", "r", stdin);
    freopen ("binary.out", "w", stdout);

    std::cin >> n >> m;

    for (int i = 1; i <= m; i++) { std::cin >> a[i]; }

    for (int i = 1; i <= m; i++) {
        for (int i = 1; i <= n; i++) { p[i] = i; }

        i64 ans = 0;
        do {
            ans += binsearch (p, 1, n, a[i]);
        } while (std::next_permutation (p + 1, p + n + 1));

        std::cout << ans << "\n";
    }

    return 0;
}