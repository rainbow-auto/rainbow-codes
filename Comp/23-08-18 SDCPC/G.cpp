#include <iostream>
#include <vector>
#include <algorithm>

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

signed main () {

    int T; cin >> T;

    while (T--) {
        a.clear ();

        cin >> n;

        for (int i = 1; i <= n; i++) {
            int now; cin >> now;
            a.push_back (Node {now, now - i});
        }

        sort (a.begin(), a.end());

        int ans = 0;
        Node last = Node { 0, -1145141919810 };
        bool skipFlag = false;
        for (auto now : a) {
            if (skipFlag) { skipFlag = false; goto beforeContinue; }
            if (now.x == last.x and now.val + last.val > 0) {
                ans = max (ans, ans + now.val + last.val);
                skipFlag = true;
            }
            beforeContinue: last = now;
        }

        cout << ans << endl;
    }


    return 0;
}