#include <iostream>
#include <set>
#include <vector>
#include <queue>

using i64 = long long;

const int maxn = 100005;

int n;
int a[maxn];

int cnt[maxn];

struct Node {
    int val;
    
    friend bool operator < (Node a, Node b) { return cnt[a.val] < cnt[b.val]; }
};

std::priority_queue<Node> rest[2];

std::vector <int> ans;

inline void solve () {
    for (int i = 1; i <= (n >> 1); i++) {
        if (rest[0].size () >= 2) {
            int x = rest[0].top ().val; rest[0].pop ();
            int y = rest[0].top ().val; rest[0].pop ();

            ans.push_back (x); ans.push_back (y);        

            cnt[x]--;
            cnt[y]--;

            if (cnt[x]) { rest[1].push (Node {x}); }
            if (cnt[y]) { rest[1].push (Node {y}); }

        } else if (rest[1].size () >= 2) {
            int x = rest[1].top ().val; rest[1].pop ();
            int y = rest[1].top ().val; rest[1].pop ();

            ans.push_back (x); ans.push_back (y);            
            
            cnt[x]--;
            cnt[y]--;

            if (cnt[x]) { rest[1].push (Node {x}); }
            if (cnt[y]) { rest[1].push (Node {y}); }

        }
        else {
            std::cout << -1 << "\n";
            return;
        }
    }

    for (auto now : ans) { std::cout << now << " "; } std::cout << "\n";
}

bool vis[maxn];

int main () {

    std::cin >> n;

    int mx = 0;
    for (int i = 1; i <= n; i++) { 
        std::cin >> a[i]; mx = std::max (mx, a[i]);
    }

    // debug
    // std::cout << n << "\n";

    solve ();

    return 0;
}