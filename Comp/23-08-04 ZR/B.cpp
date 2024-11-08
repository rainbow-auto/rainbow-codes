#include <iostream>

using namespace std;

const int maxn = 200005;

int to[maxn], pre[maxn], last[maxn], cnt;
inline void addEdge (int u, int v) {
    cnt ++;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;
}

int n;
int a[maxn], b[maxn];

int dp[maxn][3]; // 统计差: 红减蓝 + 1
void dfs (int now, int fa) {
    
    // init
    // dp[now][0] = 0x3f3f3f3f; // 蓝比红多1
    // dp[now][1] = 0x3f3f3f3f; // 一样多
    // dp[now][2] = 0x3f3f3f3f; // 红比蓝多1
    
    int son = 0;
    for (int i = last[now]; i; i = pre[i]) {
        int t = to[i];
        if (t == fa) { continue; }
    
        son ++;
        dfs (t, now); 
    
        dp[now][0] += dp[t][1] + b[now];
        dp[now][1] += min(dp[t][2] + b[now], dp[t][0] + a[now]);
        dp[now][2] += dp[t][1] + a[now];
    } 

    if (not son) { // 没有儿子
        dp[now][0] = b[now];
        dp[now][2] = a[now];        
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

    dfs (1, -1);

    int res = 0x3f3f3f3f;
    res = min (res, dp[1][0]);
    res = min (res, dp[1][1]);
    res = min (res, dp[1][2]);

    cout << res << endl;

    for (int i = 1; i <= n; i++) {
        cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    }

    return 0;
}