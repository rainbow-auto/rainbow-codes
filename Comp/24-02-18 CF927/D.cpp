#include <iostream>
#include <vector>
#include <cstring>

const int maxn = 75;

int T;

int n;
char trumpSuit;

struct Card {
    int rank;
    char suit;
} a[maxn];

inline bool canBeat (int x, int y) {
    if (a[x].suit == a[y].suit) { 
        return a[x].rank > a[y].rank;
    } else if (a[x].suit == trumpSuit) {
        return true;
    } else {
        return false;
    }
}

std::vector <int> beat[maxn];
int vis[maxn];
int match[maxn];

bool dfs (int u) {
    if (vis[u]) { return false; }
    vis[u] = true;

    for (auto v : beat[u]) {
        if (vis[v]) { continue; }
        vis[v] = true;

        if (match[v] == 0 or dfs (match[v])) {
            match[v] = u;
            return true;
        }
    }

    return false;
}

inline void clear () {
    memset (match, 0, sizeof (match));
    for (int i = 1; i <= (n << 1); i++) { beat[i].clear (); }
}

int main () {
    
    std::cin >> T;

    while (T--) {
        std::cin >> n;
        std::cin >> trumpSuit;

        for (int i = 1; i <= (n << 1); i++) {
            char rank, suit; std::cin >> rank >> suit;
            a[i] = Card { rank - '0', suit };
        }

        for (int i = 1; i <= (n << 1); i++) {
            for (int j = 1; j <= (n << 1); j++) {
                if (i == j) { continue; }

                if (canBeat (i, j)) { beat[i].push_back (j); }
            }
        }

        int sum = 0;
        for (int i = 1; i <= (n << 1); i++) {
            memset (vis, 0, sizeof (vis));
            if (dfs (i)) { sum ++; }
        }

        if (sum < n) { std::cout << "IMPOSSIBLE\n"; }
        else {
            for (int i = 1; i <= (n << 1); i++) {
                if (match[i]) { 
                    if (canBeat (match[i], i)) { 
                        std::cout << a[i].rank << a[i].suit << ' ';
                        std::cout << a[match[i]].rank << a[match[i]].suit << '\n';
                    } else {
                        std::cout << a[match[i]].rank << a[match[i]].suit << ' ';
                        std::cout << a[i].rank << a[i].suit << '\n';
                    }
                }
            }
        }

        clear ();
    }
 
    return 0;
}
