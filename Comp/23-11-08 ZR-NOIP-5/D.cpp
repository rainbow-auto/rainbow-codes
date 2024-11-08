#include <iostream>
#include <vector>

using i64 = long long;

const int maxn = 1000005;

int n;

struct Edge {
    int u, v;
    int pre;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v) {
    es[++cnt] = Edge { u, v, last[u] };
    last[u] = cnt;
}

namespace Subtask1 {
    int siz[maxn], fa[maxn], dep[maxn], son[maxn];
    void tree_build (int now) {
        siz[now] = 1;
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa[now]) { continue; }

            fa[t] = now;
            dep[t] = dep[now] + 1;
            tree_build (t);
            siz[now] += siz[t];
            if (siz[son[now]] < siz[t]) { son[now] = t; }
        }
    }

    int top[maxn];
    void tree_decomp (int now, int topnow) {
        top[now] = topnow;

        if (not son[now]) { return; }

        tree_decomp (son[now], topnow);

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa[now]) { continue; }
            if (t == son[now]) { continue; }

            tree_decomp (t, t);
        }
    }

    inline int lca (int a, int b) {
        while (top[a] != top[b]) {
            if (dep[top[a]] > dep[top[b]]) { a = fa[top[a]]; }
            else { b = fa[top[b]]; }
        }
        return dep[a] < dep[b] ? a : b;
    }

    inline int getDis (int a, int b) {
        return dep[a] + dep[b] - 2 * dep[lca (a, b)];
    }

    inline void solve () {
        dep[1] = 1;
        tree_build (1);
        tree_decomp (1, 1);
        
        int ans = 0;

        for (int u = 1; u <= n; u++) {
            for (int v = u + 1; v <= n; v++) {
                for (int w = v + 1; w <= n; w++) {
                    if (getDis (u, v) == getDis (v, w) and getDis (v, w) == getDis (w, u)) {
                        ans ++;
                    }
                }
            }
        }

        std::cout << ans << "\n";
    }
}

namespace Subtask2 {
    
    i64 ans = 0;

    int exist[maxn];
    int couple[maxn];

    std::vector<int> dis;

    void getDis (int now, int fa, int dis_fa) {
        int dis_now = dis_fa + 1;
        
        dis.push_back (dis_now);
        
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) { continue; }
            
            getDis (t, now, dis_now);
        }
    }

    inline void node_solve (int node) {
        std::vector<int> dis_remove;
        
        for (int i = last[node]; i; i = es[i].pre) {
            int t = es[i].v;

            getDis (t, node, 0);

            for (auto t_dis : dis) { ans += couple[t_dis]; }
            for (auto t_dis : dis) { couple[t_dis] += exist[t_dis]; }
            for (auto t_dis : dis) { exist[t_dis] ++; }

            for (auto t_dis : dis) { dis_remove.push_back (t_dis); }

            dis.clear ();
        }

        for (auto x : dis_remove) { exist[x] = couple[x] = 0; }
    }

    inline void solve () {
        for (int i = 1; i <= n; i++) {
            node_solve (i);
        }

        std::cout << ans << "\n";
    }
}

namespace Subtask3 {

    i64 ans = 0;

    inline i64 choose2 (i64 x) {
        return x * (x - 1) / 2;
    }

    bool removed[maxn];

    int root;
    int maxpart[maxn], sum;

    int siz[maxn];

    void getRoot (int now, int fa) {
        siz[now] = 1;

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) { continue; }
            if (removed[t]) { continue; }
            
            getRoot (t, now);
            siz[now] += siz[t];

            maxpart[now] = std::max (maxpart[now], siz[t]);
        }    

        maxpart[now] = std::max (maxpart[now], sum - siz[now]);

        if (maxpart[now] < maxpart[root]) { root = now; }
    }

    std::vector<int> dis; 
    std::vector<int> remove_dis;

    void getDis (int now, int fa, int dis_fa) {
        int dis_now = dis_fa + 1;
        dis.push_back (dis_now);
        remove_dis.push_back (dis_now);

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (t == fa) { continue; }
            if (removed[t]) { continue; }

            getDis (t, now, dis_now);
        }
    }   

    int exist[maxn];

    inline void dfz_solve (int now) {
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (removed[t]) { continue; }

            getDis (t, now, 0);

            for (auto t_dis : dis) {
                if (exist[t_dis] >= 2) { ans += choose2 (exist[t_dis]); }
            }

            for (auto t_dis : dis) { exist[t_dis] ++; }
            dis.clear ();
        }
        
        for (auto x : remove_dis) { exist[x] = 0; }
    }  

    inline void dfz (int now) {
        removed[now] = true;
        dfz_solve (now); 

        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v;
            if (removed[t]) { continue; }

            sum = siz[t];
            maxpart[root] = 0x3f3f3f3f;
            getRoot (t, now);
            getRoot (root, 0);
        
            dfz (root);
        }   
    }

    inline void solve () {
        sum = n;
        maxpart[root] = 0x3f3f3f3f;
        getRoot (1, 0);
        getRoot (root, 0);

        dfz (root);

        std::cout << ans << "\n";   
    }
}

int main () {

    std::cin >> n;
    for (int i = 2; i <= n; i++) { 
        int t; std::cin >> t;
        addEdge (i, t); addEdge (t, i);
    }

    Subtask2::solve ();

    return 0;
}