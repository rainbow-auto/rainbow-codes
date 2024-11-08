#include <iostream>

using namespace std;

const int maxn = 100005;

int n;
int to[maxn], pre[maxn], last[maxn], cnt;
inline void addEdge (int u, int v) {
    cnt ++;
    to[cnt] = v;
    pre[cnt] = last[u];
    last[u] = cnt;
}

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
                            
    }

    return 0;
}