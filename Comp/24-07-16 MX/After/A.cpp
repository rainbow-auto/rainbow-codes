#pragma GCC target("avx")
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include <iostream>

using i64 = long long;

const int maxn = 505;

const i64 mod = 1e9 + 7;

i64 n, m;
i64 dp[maxn][maxn];

i64 pw2[maxn * maxn];

int main () {

    freopen ("seg.in", "r", stdin);
    freopen ("seg.out", "w", stdout);

    std::ios::sync_with_stdio (false);

    std::cin >> n >> m;

    if (m == 0) { std::cout << 1 << "\n"; return 0; }

    pw2[0] = 1;
    for (int i = 1; i <= 500 * 500; i ++) {
        pw2[i] = 2ll * pw2[i - 1] % mod;
    }

    dp[0][0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int k = i + 1; k <= n; k ++) {
            for (int j = 0; j <= m; j ++) {
                dp[k][j + 1] = (dp[k][j + 1] + (dp[i][j] * (pw2[k - i] - 1) % mod * pw2[(n - k) * (k - i)]) % mod) % mod;
            }
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i][m] % mod) % mod;
    }   

    std::cout << ans << "\n";

    return 0;
}