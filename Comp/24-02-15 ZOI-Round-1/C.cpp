#include <iostream>
#include <cstring>
#include <ctime>

const int maxn = 55;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

int n, m;

char a[maxn][maxn], target[maxn][maxn];

inline bool check () {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (target[i][j] != 'B' and a[i][j] == 'A') { return false; }
        }
    }
    return true;
}

inline bool check_wall () {
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (target[i][j] == '#' and a[i][j] == 'A') { return true; }
        }
    }
    return false;
}

inline void print () {
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            std::cerr << a[i][j];
        }
        std::cerr << "\n";
    }
}

char bak[maxn][maxn];
int ans = 0x3f3f3f3f;

int startTime;

void solve (int step) {
    if (clock () - startTime > (double) CLOCKS_PER_SEC * 0.55) { return; } // ? ? ! !

    if (check_wall ()) { return; }
    if (check ()) { ans = std::min (ans, step); return; }

    memcpy (bak, a, sizeof (a));

    for (int id = 0; id < 4; id++) {

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == 'A') { a[i][j] = '.'; }
            }
        }  

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (bak[i][j] == 'A') { a[i + dx[id]][j + dy[id]] = 'A'; }
            }
        }  

        solve (step + 1);

        memcpy (a, bak, sizeof (bak));
    }
}

int main () {

    std::cin >> n >> m;
    
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            target[i][j] = '#';
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> target[i][j]; a[i][j] = target[i][j];
        }
    }

    startTime = clock ();

    solve (0);

    if (ans == 0x3f3f3f3f) { std::cout << "No\n-1\n"; }
    else { std::cout << "Yes\n"; std::cout << ans << "\n"; }

    return 0;
}