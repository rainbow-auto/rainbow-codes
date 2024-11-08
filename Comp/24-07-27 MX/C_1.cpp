#include <iostream>
#include <set>

#pragma GCC Optimize("Ofast")

const int maxn = 505;

int n, m;

bool a[maxn][maxn];

std::set <int> ans;

int nxt[maxn][maxn];

void dfs (int i, int j) {
    if (not j) { ans.insert (i); return; }

    if (a[i][j]) {
        if (i == 1) { 
            dfs (i + 1, j - 1);
        } else if (i == n) {
            dfs (i - 1, j - 1);
        } else {
            dfs (i + 1, j - 1);
            dfs (i - 1, j - 1);
        }
    } else {
        dfs (i, nxt[i][j]);
    }
}

int main () {

    freopen ("garlic.in", "r", stdin);
    freopen ("garlic.out", "w", stdout);

    int T; std::cin >> T;

    while (T--) {
        std::cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            int last = 0;
            for (int j = 1; j <= m + 1; j++) {
                char c; std::cin >> c;
                if (c == '1') { 
                    a[i][j] = 1; 
                    last = j;
                } else { 
                    a[i][j] = 0; 
                }
                nxt[i][j] = last;
            }
        }

        for (int i = 1; i <= n; i++) {
            ans.clear ();
            dfs (i, m + 1);
            std::cout << ans.size () << " ";
        }        
        std::cout << "\n";
    }

    return 0;
}