#include <iostream>

using namespace std;

const int maxn = 505;

struct Edge {
    int u, v;
    int pre;
    int w;
} es[maxn << 1];

int last[maxn], cnt;

inline void addEdge (int u, int v, int w) {
    es[++cnt] = Edge { u, v, last[u], w };
    last[u] = cnt;
}

namespace Task1 {

    bool check (int u, int v, int fa) {
        int son_u = 0;
        for (int i = last[u]; i; i = es[i].pre) {
            int t = es[i].v; if (t == fa) { continue; }
            son_u ++;
        }
        for (int j = last[v]; j; j = es[j].pre) {
            int t = es[j].v; if (t == fa) { continue; }
            son_v ++;
        }

        if (son_u != son_v) { return false; }

        for (int i = last[u]; i; i = es[i].pre) {
            int ut = es[i].v; if (t == fa) { continue; }
            for (int j = last[v]; j; j = es[j].pre) {
                int vt = es[j].v; if (t == fa) { continue; }
                
                if (check (ut, vt, now)) { return true; }
            }   
        }
        return false;
    }

    struct BCJ {
        int fa[maxn];
        int siz[maxn];
        BCJ (siz) { for (int i = 1; i <= n; i++) { fa[i] = i; siz[i] = 1; } }

        void find (int x) {
            if (fa[x] == x) { return fa[x]; }
            else { return fa[x] = find (fa[x]); }
        }

        void merge (int u, int v) {
            u = find (u);
            v = find (v);

            if (u == v) { return; }
            else { fa[u] = v; siz[v] += siz[u]; }
        }
    }

    void dfs (int now, int fa) {
        vector<int> sons;
        for (int i = last[now]; i; i = es[i].pre) {
            int t = es[i].v; if (t == fa) { continue; }
            sons.push_back (t);
        }

        BCJ f(sons.size());

        for (auto u : sons) {
            for (auto v : sons) {
                if (u == v) { continue; }

                if (check (u, v, now)) { f.merge (u, v); }
            }
        }

        for (int i = 1; i <= n; i++)
    }

    inline void solve () {
        
    }

}

int main () {

    return 0;
}