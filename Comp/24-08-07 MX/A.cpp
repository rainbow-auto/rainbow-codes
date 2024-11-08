#include <iostream>
#include <algorithm>
#include <map>

const int maxn = 1000005;

int n;
std::string a, b;

int cnt_a[256], cnt_b[256]; 
inline bool chk () {
    for (int i = 1; i <= n; i++) { cnt_a[a[i]] ++; }
    for (int i = 1; i <= n; i++) { cnt_b[b[i]] ++; }

    bool res = true;
    for (int i = 0; i < 256; i++) { res &= (cnt_a[i] == cnt_b[i]); }

    return res;
}

int main () {

    freopen ("move.in", "r", stdin);
    freopen ("move.out", "w", stdout);

    std::cin >> a;
    std::cin >> b;
    
    n = a.size ();
    a = " " + a; b = " " + b;

    if (not chk ()) { std::cout << -1 << "\n"; return 0; }

    int apos = n;
    int bpos = n;

    while (apos > 0 and bpos > 0) {
        if (a[apos] == b[bpos]) { bpos --; }
        apos --;
    }

    std::cout << bpos << "\n";

    return 0;
}