#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 2005;

int n, r;
int a[maxn];

int main () {

    std::cin >> n >> r;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    std::vector <int> ans;

    bool flag = true;
    while (flag) {
        for (int i = 1; i <= n; i++) { std::cerr << a[i] << " "; } std::cerr << "\n";

        flag = false;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) { continue; }

            if (i == 1 or i == n) { a[i] = 1; ans.push_back (i); continue; }   
            if (a[i - 1] != a[i + 1]) { a[i] = 1; ans.push_back (i); continue; }
            
            flag = true;
        }
    }

    std::cout << ans.size () << "\n";
    for (auto now : ans) { std::cerr << now << " "; } std::cerr << "\n";

    return 0;
}