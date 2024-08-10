#include <iostream>
#include <string>

const int maxn = 1005;

int n, m;
char a[maxn][maxn];

bool vis[maxn][maxn];

std::string s[maxn];

int right[maxn];

int main () {

    std::cin >> n;

    for (int i = 1; i <= n; i++) { std::cin >> s[i]; m = std::max (m, (int) s[i].size ()); }

    for (int i = n; i >= 1; i--) {
        int curr = 0;
        for (auto c : s[i]) {
            a[++curr][n - i + 1] = c;
            vis[curr][n - i + 1] = true;
            right[curr] = std::max (right[curr], n - i + 1);
        }   
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (not vis[i][j]) { 
                if (j <= right[i]) { std::cout << "*"; }
                else { std::cout << " "; }
            } else {
                std::cout << a[i][j];
            }
        }
        if (i != m) { std::cout << "\n"; }
    }

    return 0;
}