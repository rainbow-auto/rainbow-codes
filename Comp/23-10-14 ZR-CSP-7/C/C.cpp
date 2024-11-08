#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using std::cin;
using std::cout;

#define endl "\n"

const int maxn = 700005;
const int inf = 600000;

const unsigned long long mod = 998244353ull;
const unsigned long long base = 233ull;

int n, Q;
unsigned long long a[maxn];

namespace Get {

    struct BIT {
        int tr[maxn];
        
        inline int lowbit (int x) { return x & (-x); }

        inline void add (int pos, int val) { for (int i = pos; i <= n; i += lowbit(i)) { tr[i] += val; } }
        inline int query (int pos) { int res = 0; for (int i = pos; i; i -= lowbit(i)) { res += tr[i]; } return res;  }

        inline void clear () { memset (tr, 0, sizeof (tr)); }
    } tr;

    inline long long getCnt () {
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += i - 1 - tr.query (a[i]);
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
    long long ansNow = 0ull;

    std::deque <long long> q;
    long long ans[maxn];
    long long pow[maxn];

    inline void solve () {
        ansNow = Get::getCnt ();

        for (int i = 1; i <= n; i++) { q.push_back (a[i]); }

        for (int i = 1; i <= Q; i++) {
            char op; cin >> op;

            if (op == '0') {
                if (curr) {
                    long long now = q.front();
                    ansNow -= now - 1;
                    ansNow += n - now;
                    
                    q.pop_front ();
                    q.push_back (now);
                } else {
                    long long now = q.back ();
                    ansNow -= now - 1;
                    ansNow += n - now;

                    q.pop_back();
                    q.push_front(now);                    
                }
            } else if (op == '1') {
                ansNow = 1ull * n * (n - 1) / 2 - ansNow; 
                curr ^= 1;
            }

            // cout << ansNow << endl;

            ans[i] = ansNow;
        }

        pow[0] = 1ull;
        for (int i = 1; i <= Q; i++) {
            pow[i] = 1ull * pow[i - 1] * base % mod;
        }

        long long final_ans = 0ull;
        for (int i = 1; i <= Q; i++) {
            final_ans = (final_ans + 1ull * ans[i] % mod * pow[Q - i] % mod) % mod;
        }

        cout << final_ans << endl;
    }   

}

int main () {
    // freopen ("ex_he5.in", "r", stdin);
    // freopen ("C.out", "w", stdout);

    cin >> n >> Q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    Solution::solve ();

    return 0;
}
