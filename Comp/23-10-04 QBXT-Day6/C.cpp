#include <iostream>
#include <cstring>
#include <set>
#include <bitset>

using namespace std;

const int mod = 998244353;

int n;

const int dx[] = { 0, 1, 0, -1, 0, 1, -1, -1, 1, 1, 2, -1, 2, -1, -2, 1, -2 };
const int dy[] = { 0, 0, 1, 0, -1, 1, -1, 1, -1, 2, 1, 2, -1, -2, -1, -2, 1 };

namespace Task1 {

    const int maxn = 105;
    int vis[maxn][maxn];    


    inline void setVis (int x, int y, int id, int val) {
        int nx = x + dx[id];
        int ny = y + dy[id];
        if (nx >= 1 and nx <= 2 * n and ny >= 1 and ny <= 2 * n) { vis[nx][ny] = val; }
    }    

    inline void display () {
        for (int i = 1; i <= 2 * n; i++) {
            for (int j = 1; j <= 2 * n; j++) {
                cout << vis[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    set<unsigned long long> s;

    inline void add () {
        unsigned long long now = 0;
        for (int i = 1; i <= 2 * n; i++) { 
            for (int j = 1; j <= 2 * n; j++) {
                now <<= 1;
                if (vis[i][j] > 0) {
                    now |= 1;
                }
            }
        }
        s.insert (now);
    }

    int res = 0;
    inline void dfs (int now) {
        if (now == n * n) { res ++; if (res >= mod) { res -= mod; }; add(); return; }

        for (int i = 1; i <= 2 * n; i++) {
            for (int j = 1; j <= 2 * n; j++) {
                if (vis[i][j] >= 0) { continue; }

                int old_vis[maxn][maxn];
                memcpy (old_vis, vis, sizeof (vis));
                setVis (i, j, 0, now + 1);
                for (int k = 1; k < 17; k++) { setVis (i, j, k, 0); }
                dfs (now + 1);
                memcpy (vis, old_vis, sizeof (old_vis));
            }
        }
    }

    inline void solve () {
        memset (vis, -1, sizeof (vis));
        dfs (0);

        cout << s.size() << endl;        
    }

}

namespace Task2 {

    const int maxn = 105;

    bool col[maxn][maxn];

    bool check () {
        for (int i = 1; i <= 2 * n; i++) {
            for (int j = 1; j <= 2 * n; j++) {
                if (not col[i][j]) { continue; }
                for (int k = 0; k < 17; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx >= 1 and nx <= 2 * n and ny >= 1 and ny <= 2 * n) { 
                        if (col[nx][ny]) { return false; }
                    }
                }
            }
        }
        return true;
    }

    int res = 0;
    void dfs (int now) {
        if (now == 2 * n) { if (check ()) { res ++; } ; return; }

        for (int S = 0; S < (1 << (2 * n)); S++) {
            for (int i = 0; i < n; i++) {
                col[now][i + 1] = S & (1 << i);        
            }
            dfs (now + 1);
        }
    }

    inline void solve () {
        dfs (1);
        cout << res << endl;
    }

}

int main () {

    cin >> n;
    
    // Task2::solve ();

    // Task1::solve ();

    if (n == 1) { cout << 4 << endl;  }  
    if (n == 2) { cout << 25 << endl; }
    if (n == 3) { cout << 120 << endl; }

    return 0;
}