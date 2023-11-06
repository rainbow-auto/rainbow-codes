#include <iostream>

using namespace std;

const int maxn = 500005;
const int mod = 2027;

int n, m;
int s[maxn];

namespace Task1 {
    long long ans = 0;

    bool vis[maxn];
    void dfs (int now) {
        if (now == n) { 
            long long ansnow = 1;
            for (int i = 0; i < n; i++) { ansnow *= vis[i] ? (i + 1) : 1; ansnow %= mod; }
            ans += ansnow; ans %= mod;
            return;
        } 
        if (now > n) { return; }
    
        vis[now] = true;
        for (int i = 1; i <= m; i++) {
            dfs (now + s[i]);
        }
        vis[now] = false;  
    }    

    inline void solve () {
        dfs (0);
        cout << ans << endl; 
    }
}

int main () {

    cin >> n >> m;

    for (int i = 1; i <= m; i++) { cin >> s[i]; }

    Task1::solve ();

    return 0;
}