#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

const int maxn = 1005;
const int maxv = 100005;

int n;
int a[maxn];

namespace Solution {
    int r[maxv]; // 每个质因子出现的最多次数
    int p[maxn], pcnt; // 大于maxv的质因子都有哪些

    inline void solve () {

        for (int i = 1; i <= n; i++) {
            for (int j = 2; j * j <= a[i]; j++) {
                int nowCnt = 0;
                while (a[i] % j == 0) { nowCnt ++; a[i] /= j; }
                r[j] = max (r[j], nowCnt);
            }

            // 没分解干净
            if (a[i] >= maxv) { p[++pcnt] = a[i]; }
            else if (a[i] > 0) { r[a[i]] = max (r[a[i]], 1); }
        }

        sort (p + 1, p + pcnt + 1);
        pcnt = unique (p + 1, p + pcnt + 1) - p - 1;

        int lcm = 1;
        for (int i = 1; i <= maxv; i++) { for (int j = 1; j <= r[i]; j++) { lcm = 1ll * lcm * i % mod; } } // 把所有 < maxv 的质因子乘起来
        for (int i = 1; i <= pcnt; i++) { lcm = 1ll * lcm * p[i] % mod; } // 把所有 >= maxv 的质因子乘起来
    
        cout << lcm << endl;
    }  

}


int main () {

    freopen ("buy.in", "r", stdin);
    freopen ("buy.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) { cin >> a[i]; }

    Solution::solve ();

    return 0;
}