#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using std::cin;
using std::cout;

#define endl "\n"

#define int long long

const int maxn = 700005;
const int inf = 600000;

const unsigned long long mod = 998244353ull;
const unsigned long long base = 233ull;

int n, Q;
int a[maxn];

namespace Get {

    struct BIT {
        int tr[maxn];
        
        inline int lowbit (int x) { return x & (-x); }

        inline void add (int pos, int val) {  for (int i = pos; i <= n; i += lowbit(i)) { tr[i] += val; } }
        inline int _query (int pos) { int res = 0; for (int i = pos; i; i -= lowbit(i)) { res += tr[i]; } return res;  }

        inline int query (int l, int r) { if (l > r) { return 0; } else { return _query (r) - _query (l - 1); } }

        inline void clear () { memset (tr, 0, sizeof (tr)); }
    } tr;

    inline int getCnt () {
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            ans += tr.query (1, a[i]);
            tr.add (a[i], 1); // 整体都加1
        }
        return ans;
    }

}

namespace Solution {
    
    // 当前顺序:
    // curr == true : 正序
    // curr == false : 反序
    int curr = true;
    int ansNow = 0;

    std::deque <int> q;
    int ans[maxn];

    inline void solve () {
        ansNow = Get::getCnt ();

        for (int i = 1; i <= n; i++) { q.push_back (a[i]); }

        for (int i = 1; i <= Q; i++) {
            char op; cin >> op;

            if (op == '0') {
                if (curr) {
                    int now = q.front();
                    ansNow -= now - 1;
                    ansNow += n - now;
                    
                    q.pop_front ();
                    q.push_back (now);
                } else {
                    int now = q.back ();
                    ansNow -= now - 1;
                    ansNow += n - now;

                    q.pop_back();
                    q.push_front(now);                    
                }
            } else if (op == '1') {
                ansNow = 1ull * n * (n - 1) / 2 - ansNow; 
                curr = !curr;
            }

            ans[i] = ansNow;
        }

        unsigned long long final_ans = 0ull;
        unsigned long long pow = 1ull;
        for (int i = Q; i >= 1; i--) {
            final_ans += 1ull * pow * ans[i];
            final_ans %= mod;
            pow *= base;
            pow %= mod;
        }

        cout << final_ans << endl;
    }   

}

signed main () {

    cin >> n >> Q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    Solution::solve ();

    return 0;
}