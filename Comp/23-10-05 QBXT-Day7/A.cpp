// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <iostream>
#include <cstring>

using namespace std;

long long n, k;

namespace Task1 {

    const int maxn = 55;

    struct Ans {
        int cnt;
        int a[maxn][maxn];
    };

    int a[maxn][maxn];

    int b[maxn][maxn];
    bool check () {
        memset (b, 0, sizeof (b));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    b[i][j] |= a[i][k] * a[k][j];            
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                res += b[i][j];
            }
        }

        return res == 0;
    }

    inline int count () {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                res += a[i][j];
            }
        }
        return res;
    }

    int res = 0;
    Ans ans;

    void dfs (int now) {
        if (now > n * n) {
            int cnt = count ();
            if (check ()) {
                if (res < cnt) {
                    res = cnt;
                    ans.cnt = cnt;
                    memcpy (ans.a, a, sizeof (a));
                }    

                // res = max (res, cnt);
            }
            return;
        }

        now ++;
        a[now / n + 1][now % n + 1] = 1;
        dfs (now);
        a[now / n + 1][now % n + 1] = 0;
        dfs (now);
    }

    void solve () {

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cin >> a[i][j];
        //     }
        // }

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << "a[" << i << "][" << j << "] = " << a[i][j] << ";" << endl; 
        //     }
        // }

        dfs (1);

        cout << res << endl;

        cout << ans.cnt << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << ans.a[i][j] << " ";
            }
            cout << endl;
        }
    }

}

namespace Task2 {

    inline void solve () {
        if (n % 2 == 0) {
            long long res = n * n / 4ll;
            cout << res << endl;
        } else {
            long long res = (long long)(n / 2) * (long long)((n + 1) / 2);
            cout << res << endl;
        }
    }

}

int main () {

    cin >> n >> k;

    // Task1::solve ();
    
    Task2::solve ();

    return 0;
}

/*
1:
1
0

2:
1
0 1
0 0

3:
2
0 1 1
0 0 0
0 0 0

4:
0 0 1 1
0 0 1 1
0 0 0 0
0 0 0 0

5:

0 0 1 1 1 
0 0 1 1 1 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 

偶数:

n * n / 4

奇数:

(n / 2 上取整) * (n / 2 下取整)

*/