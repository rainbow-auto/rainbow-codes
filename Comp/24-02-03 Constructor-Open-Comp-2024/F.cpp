#include <iostream>
#include <set>

const int maxn = 200005;

int T;

int n;
int d[maxn];
int x[maxn];

std::set<int> vis;

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> n;

        int len = 0;
        for (int i = 1; i <= n; i++) { std::cin >> d[i]; len = std::max (len, d[i]); }

        for (int i = 1; i <= n; i++) {
            x[i] = d[i];
            if (vis.count(x[i])) { x[i] = len - x[i]; }
            vis.insert (x[i]);
        }
        
        for (int i = 1; i <= n; i++) { std::cout << x[i] << " "; } std::cout << "\n";
        
        vis.clear ();
    }

    return 0;
}