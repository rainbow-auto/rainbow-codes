#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int maxn = 500005;

inline void read() {  } template < typename Tp, typename... Tp2 > inline void read(Tp &x, Tp2 &... oth) {
    x=0;
    char ch=getchar();
    Tp f=1;
    while(!isdigit(ch)) {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch)) {
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
    read(oth...);
}
template<typename Tp>void write(const Tp &x) {
    if(x<10)putchar(x+'0');
    else {
        write(x/10);
        putchar(x%10+'0');
    }
}

int n, q;

set<int> to[maxn];

set<int> s;

namespace Task3 {

    // struct Node {
    //     int id, dfn, dep;

    //     friend bool operator < (Node a, Node b) {
    //         if (a.dep != b.dep) {return a.dep < b.dep;}
    //         else {return a.dfn < b.dfn;}
    //     }
    // };
    
    // set<Node> s;

    // int dep[maxn], dfn[maxn], dpos;
    // void preProcess () {
    //     for (auto now : ::s) {
    //         s.insert (Node{now, dfn[now], dep[now]});
    //     }
    // }

    void solve() {
        // preProcess ();
        
        int cnt = 0;
        for (auto now : s) {
            for (auto t : to[now]) {
                if (s.count(now) and s.count(t)) {cnt ++;}
            }
        }   
        cout << cnt / 2 << endl;
    }
}

namespace Task2 {
    void solve (int u, int v) {
        if (to[u].count(v) or to[v].count(u)) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
}

namespace Task1 {
    int cnt = 0;
    void dfs (int now, int fa) {
        for (auto t : to[now]) {
            if (t == fa) continue;
            
            if (s.count(now) and s.count(t)) {cnt++;}
            dfs (t, now);
        }            
    }

    void solve () {
        cnt = 0;
        dfs (1, 0);
        cout << cnt << endl;
    }
}

int main () {

    ios::sync_with_stdio (false); cin.tie (0); cout.tie (0);

    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        to[u].insert(v);
        to[v].insert(u);
    }

    cin >> q;

    while (q--) {
        s.clear();
        int s_siz; cin >> s_siz;

        if (s_siz == 2) {
            int u, v; cin >> u >> v;
            Task2::solve(u, v);
        } else {
            for (int i = 1; i <= s_siz; i++) {
                int now; cin >> now;
                s.insert(now);
            }

            if (s_siz <= 5000 and n <= 5000){
                Task1::solve();
            } else {
                Task3::solve();
            }
        }

    }

    return 0;
}