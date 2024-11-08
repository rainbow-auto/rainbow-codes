#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 200005;

int to[maxn], pre[maxn], last[maxn];
int cnt;
inline void addEdge (int u, int v) {
    cnt ++;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;
}

int n;
int a[maxn], b[maxn];

namespace Task1 {
    int rnum[maxn], bnum[maxn];
    bool flag = true;
    int check (int now, int fa, int S) {
        rnum[now] = (S & (1 << (now - 1))) ? 1 : 0;
        bnum[now] = (S & (1 << (now - 1))) ? 0 : 1;

        int res = (S & (1 << (now - 1))) ? a[now] : b[now];
        for (int i = last[now]; i; i = pre[i]) {
            int t = to[i];
            if (t == fa) { continue; }

            res += check (t, now, S);

            rnum[now] += rnum[t];   
            bnum[now] += bnum[t];   
        }
        
        if (abs(rnum[now] - bnum[now]) > 1) { flag = false; return -1; }
        else { return res; }
    }
    
    int solve () {
        int res = 0x3f3f3f3f;
        for (int S = 0; S < (1ull << n); S++) {
            memset (rnum, 0, sizeof(rnum));
            memset (bnum, 0, sizeof(bnum));

            // res = min (res, check(1, -1, S));
            flag = true;
            int now = check(1, -1, S);
            if (now < res and flag) {
                res = now;
            }
        }
        return res;
    }   
}

namespace Task2 {
    map<int, int> dp;
    
    int solve () {
        
    }   
}

int main () {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    } 

    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        addEdge (u, v);
        addEdge (v, u);
    }

    cout << Task1::solve() << endl;

    return 0;
}