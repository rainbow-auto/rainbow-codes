// 错完了
// 摆了

#include<bits/stdc++.h>
#define rep(_id, _st, _ed) for (int _id = (_st); _id <= (_ed); _id++)
#define per(_id, _st, _ed) for (int _id = (_st); _id >= (_ed); _id--)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << " : " << (x) << "\n"; 
#define dbendl std::cerr << "\n";

using i64 = long long;
using f64 = double;

const int maxn = 5000005;

int n;
std::string s;

namespace Solution {
    int pi[maxn];
    inline void get_pi() {
        pi[1] = 0;
        rep (i, 2, n) {
            int j = pi[i - 1];
            while (j and (s[j + 1] != s[i])) j = pi[j];
            pi[i] = j + bool(s[j + 1] == s[i]);
        }
    }

    int f[maxn];

    int sum[maxn];
    inline void solve() {
        get_pi();

        f[1] = 0;
        rep (i, 2, n) {
            int j = f[i - 1];
            while (j and (s[j + 1] != s[i])) j = pi[j];
            j += (s[j + 1] == s[i]);
            while (j > (i >> 1)) j = pi[j];
            f[i] = j;
        }

        rep (i, 1, n) sum[i] = sum[pi[i]] + bool ((not (i & 1)) and (f[i] == (i >> 1))); 

        int k = (n / 100000) + !!(n % 100000);
        dbg(k);
        for (int i = 1; i <= n; i += k) {
            int res = 0;
            rep (j, i, i + k - 1) {
                res += sum[f[j]];
            }
            std::cout << res << "\n";
        }
    }
}

int f[maxn];

int main() {

    std::cin >> s;
    n = s.length();
    s = " " + s;
    
    Solution::solve();

    return 0;
}