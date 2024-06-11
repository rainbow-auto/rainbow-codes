// use Task1 

#include <iostream>
#include <set>
#include <cstring>
#include <cstdlib>

const int maxn = 500010;

int n;
int a[maxn];

namespace Task1 {

    int nxt[maxn], head;

    std::set <int> winner;

    void dfs () {

        int ec = 0; // exist count
        int now = head;
        while (nxt[now]) { now = nxt[now]; ec++; }

        if (ec == 1) { winner.insert (nxt[head]); return; }

        now = head; int pre;

        while (nxt[now]) {
            now = nxt[pre = now];

            if (not nxt[now]) { break; }

            if (a[now] > a[nxt[now]] or a[now] == a[nxt[now]]) {
                a[now] ++;
                
                int old_nxt_now = nxt[now];
                nxt[now] = nxt[nxt[now]];
            
                dfs ();

                nxt[now] = old_nxt_now; 

                a[now] --;
            }
            
            if (a[now] < a[nxt[now]] or a[now] == a[nxt[now]]) {
                a[nxt[now]] ++;
                nxt[pre] = nxt[now];
                
                dfs ();

                nxt[pre] = now;
                a[nxt[now]] --;
            }
        }
    }
    
    inline void init () {
        head = n + 5;
        nxt[head] = 1;
        for (int i = 1; i <= n - 1; i++) { nxt[i] = i + 1; }
    }

    inline void solve () {
        init ();

        dfs ();

        std::cout << winner.size () << "\n";
        for (auto now : winner) { std::cout << now << " "; }
    }
}

namespace Task2 {

    std::set <int> winner;

    inline void solve () {
        a[0] = a[n + 1] = 0x3f3f3f3f;

        for (int i = 1; i <= n; i++) {
            int l = i - 1; int r = i + 1;

            int iq = a[i]; // 智力值

            while (a[l] <= iq or a[r] <= iq) {
                if (a[l] <= iq) { iq ++; l --; }
                if (a[r] <= iq) { iq ++; r ++; }
            }

            if (l == 0 and r == n + 1) { winner.insert (i); }
        }

        std::cout << winner.size () << "\n"; 
        for (auto now : winner) { std::cout << now << " "; }
        std::cout << "\n";
    }
}

int main () {

    std::cin >> n;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }

    Task1::solve ();

    return 0;
}