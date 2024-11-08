#include <iostream>

using i64 = long long;

int n, m;

int a[maxn], b[maxn];
int t[maxn];

std::vector<int> x, y;
std::vector<int> z;

int main () {

    std::cin >> n >> m >> k;
        
    for (int i = 1; i <= n; i++) {
        std::cin >> t[i] >> a[i] >> b[i];
        if (a[i] and b[i]) { z.push_back (t[i]); }
        else if (a[i]) { x.push_back (t[i]); }
        else if (b[i]) { y.push_back (t[i]); }
    }

    if (x.size () + z.size () < k) { cout << "-1" << "\n"; return 0; }
    if (y.size () + z.size () < k) { cout << "-1" << "\n"; return 0; }
    if (x.size () + y.size () + z.size () < m) { cout << "-1" << "\n"; return 0; }

    

    return 0;
}