#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define int long long

const int maxn = 500005;

struct Node {
    int val, x;
    friend bool operator < (Node a, Node b) {
        if (a.x != b.x) { return a.x < b.x; }
        else { return a.val > b.val; }
    }
};

vector<Node> a;

int n;

int cur = 0;
vector<int> cut[maxn];

inline void clear () {
    for (int i = 1; i <= cur; i++) { cut[i].clear(); } cur = 0;
    a.clear();
}

signed main () {
    
    int T; cin >> T;
    while (T--) {
        cin >> n;

        for (int i = 1; i <= n; i++) { int now; cin >> now; a.push_back (Node { now, now - i }); }

        sort (a.begin(), a.end());
    
        Node last = Node { 0, -1 };
        for (auto now : a) {
            if (now.x != last.x) { cur ++; }
            cut[cur].push_back (now.val);
            last = now;
        }

        int ans = 0;
        for (int i = 1; i <= cur; i++) {
            int ansnow = 0;
            int chooseCnt = 0, lastChoose = 0;
            int firstFu = -0x3f3f3f3f3f3f3f3f;

            for (auto now : cut[i]) { if (now > 0) { ansnow += now; chooseCnt ++; lastChoose = now; } else { firstFu = now; break; } }
            if (chooseCnt & 1) { ansnow += max(-lastChoose, firstFu); }

            ans += ansnow;
        }

        cout << ans << endl;
    
        clear ();
    }

    return 0;
}