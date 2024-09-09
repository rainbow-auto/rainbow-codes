#include <bits/stdc++.h>

using namespace std;

const int M = 105, P = 1e9 + 7;

int ksm(int x, int y = P - 2) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}

int p[M], vis[M], f[1 << 20];

signed main() {
    // freopen("b.in", "r", stdin);
    // freopen("b.out", "w", stdout);

    int n, m; scanf("%d%d", &n, &m);
    map<int, int> M;
    for (int i = 1; i <= m; ++i) scanf("%d", &p[i]);
    for (int i = 1; i <= m; ++i) {
        if (!vis[i]) {
            int l = 0;
            for (int j = i; !vis[j]; j = p[j]) {
                ++l, vis[j] = 1;
            }
            M[l] += l;
        }
    }

    vector< pair<int, int> > z;
    for (auto x : M) {
		z.push_back(x);
	}

    int res = 0;
    for (int i = 1; i < 1 << (int)z.size(); ++i) {
		long long val = 1; // lcm
        int ct = 0;
        for (int j = 0; j < (int)z.size(); ++j) {
            if ((i >> j) & 1) {
                val = val / __gcd(val, (long long)z[j].first) * z[j].first;
                ct += z[j].second;
            }
        }

        std::cerr << i << "\n";
        std::cerr << "sum = " << ct << "\n";
        std::cerr << "lcm = " << val << "\n";

        f[i] = 1ll * ksm(1ll * ct * ksm(m) % P, n); // \frac{(\sum l_i cnt_{l_i}) ^ n}{m ^ n} 
        for (int j = (i - 1) & i; j; j = (j - 1) & i) {
            ((f[i] -= f[j]) < 0) && (f[i] += P);
        }

        std::cerr << "delta: " << 1ll * val % P * f[i] % P << "\n";

        res = (res + 1ll * val % P * f[i]) % P;
    }
	
	// std::cerr << 1ll * res * ksm (m, n) % P << "\n";

    printf("%d\n", res);
    return 0;
}

/*
1
sum = 14
lcm = 7
delta: 144265726
2
sum = 86
lcm = 86
delta: 758733393
3
sum = 100
lcm = 602
delta: 282014541
*/