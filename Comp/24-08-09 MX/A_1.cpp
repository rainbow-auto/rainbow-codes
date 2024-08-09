#include <iostream>
#include <algorithm>
#include <set>

using i64 = long long;

const int maxn = 500005;

int n;
int a[maxn];

int cnt[maxn];

std::multiset <int> s;

int main () {

    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        cnt[a[i]] ++;
    }

    for (int i = 1; i <= n; i++) { if (cnt[i] != 0) { s.insert (cnt[i]); } }

    int ans = 0;
    int pre = 0;
    for (auto now : s) {
        if (s.upper_bound (pre + now) == s.end ()) { 
            s.erase (s.upper_bound (pre));
            pre = now; ans ++; 
        } else {
            pre += now; 
            s.erase (now);
        }
    }

    if (pre != 0) { ans ++; }

    std::cout << ans << "\n";

    return 0;
}