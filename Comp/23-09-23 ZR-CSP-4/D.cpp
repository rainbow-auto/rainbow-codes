#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

const long long mod = 998244353;

int n;

namespace Task1 {

    const int maxn = 105;

    struct Edge {
        int u, v;
        int pre;
    } es[maxn * maxn];

    int last[maxn], cnt;

    inline void addEdge (int u, int v) {
        es[++cnt] = Edge { u, v, last[u] };
        last[u] = cnt;
    }

    int ind[maxn];

    bool disabled[maxn];
    set<int> s;

    void dfs () {
        for (auto now : s) {
            s.erase (now);
            disabled[now] = true;

            for (int i = last[now]; i; i = es[i].pre) {
                int t = es[i].v;
                if (disabled[t]) { continue; }

                ind[t] --;
            }

            for (int i = 1; i <= n; i++) {
                if (ind[t])
            }

            dfs ();
        }
    }

    inline void solve () {
        for (int i = 1; i <= n - 1; i++) {
            int u, v; cin >> u >> v;
            ind[u] ++;
            ind[v] ++;
        }

        for (int i = 1; i <= n; i++) {
            if (ind[i] == 1) { s.insert (i); }
        }
    }
}

namespace makeTable {
    
    deque<int> q;
    vector<int> resnow;
    int res;

    inline void display () {
        for (auto now : resnow) {
            cout << now << " ";
        }
        cout << endl;
    }

    void dfs () {
        
        if (q.empty ()) { res ++; display (); return; }

        int old_front = q.front (); q.pop_front ();
        resnow.push_back (old_front);
        dfs ();
        resnow.pop_back ();
        q.push_front (old_front);

        int old_back = q.back (); q.pop_back ();
        resnow.push_back (old_back);
        dfs ();
        resnow.pop_back ();
        q.push_back (old_back);
    }

    void solve () {
        for (int i = 1; i <= 3; i++) { q.push_back (i); }
        
        dfs ();

        cout << res << endl;
    }

}

namespace Task3 { // 链
    inline void solve () {
        long long res = 1ll;
        for (int i = 1; i <= n - 1; i ++) {
            res <<= 1ll;
            res %= mod;
        }

        cout << res << endl;
    }
}

int main () {

    // makeTable::solve ();

    cin >> n;

    Task3::solve ();

    return 0;
}