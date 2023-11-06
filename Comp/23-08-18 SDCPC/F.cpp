#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int mod = 998244353;

struct Node {
    int l, r;
    int id;

    friend bool operator <  (Node a, Node b) {
        if (a.r != b.r) { return a.r < b.r; }
        else { return a.l < b.l; }
    }  

    friend bool operator == (Node a, Node b) {
        return a.r == b.r;
    }
};

int n;
vector<Node> red;
vector<Node> blue;

inline int ksm (int a,int b)

int main () {

    int T; cin >> T;
    
    while (T--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int l, r, c; cin >> l >> r >> c;
            if (c == 0) { red.push_back (Node{l, r, 0}); }
            if (c == 1) { blue.push_back (Node{l, r, 0}); }
        }

        sort (red.begin(), red.end());
        sort (blue.begin(), blue.end());
        
        for (int i = 0; i < red.size(); i++) { red[i].id = i; }

        int sub = 0;
        for (auto now : blue) {
            int lid = lower_bound (red.begin(), red.end(), now.l) .id;
            int rid = upper_bound (red.begin(), red.end(), now.r) .id;
            sub += rid - lid;
        }

        int ans = ksm (2, n) - sub;

        cout << ans % mod << endl;
    }


    return 0;
}