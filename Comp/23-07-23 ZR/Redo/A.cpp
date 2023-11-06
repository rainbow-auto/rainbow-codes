#include <iostream>
#include <cstring>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 500005;

int to[maxn], pre[maxn], last[maxn];
int cnt;
inline void addEdge (int u, int v) {
    cnt ++;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;
}

int fa[maxn];

void dfs (int now, int fanow) {
    for (int i = last[now]; i; i = pre[i]) {
        int t = to[i];
        if (t == fanow) {
            continue;
        }
        fa[t] = now;
        
        dfs (t, now);
    }
}

bool ins[maxn];
int s[maxn];

int main () {
    fastread
    
    int n; cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        addEdge (u, v);
        addEdge (v, u);
    }

    dfs (1, 0);

    int q; cin >> q;

    Begin:;

    // while (q--) {

        int s_siz; cin >> s_siz;

        for (int i = 1; i <= s_siz; i++) {
            cin >> s[i]; ins[s[i]] = true;
        }

        int cnt = 0;
        for (int i = 1; i <= s_siz; i++) {
            if (ins[fa[s[i]]]) {
                cnt ++;
            }
        }
        cout << cnt << endl;
        // clear
        for (int i = 1; i <= s_siz; i++) {
            ins[s[i]] = false;
        }

        if (q-- > 1) goto Begin; 
        
    // }

    return 0;
}