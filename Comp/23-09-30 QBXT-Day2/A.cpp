#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 200005;

int n, m;
int a[maxn];

namespace Task1 {

    const int maxn = 5005;
    const int maxm = 1000005;

    int is_prime[maxm];
    vector <int> primes;
    inline void getPrimes () {
        memset (is_prime, 1, sizeof (is_prime));
        for (int i = 2; i <= n; i++) {
            if (is_prime[i]) { primes.push_back (i); }

            for (auto j : primes) {
                if (i * j > n) { break; }
                is_prime[i * j] = false;
                if (i % j == 0) { break; }
            }
        }
    }

    int mx;
    vector < pair <int, int> > prefix[maxn];
    int t[maxm];

    int decompsedN[maxm];

    inline void preProcess () {
        sort (a + 1, a + m + 1);
        mx = a[m];

        getPrimes ();

        for (int i = 2; i <= mx; i++) {
            int cnt = 0;

            for (auto p : primes) {
                if (p > i) { break; }
                
                int cnt = 0;
                for (int j = p; j <= i; j *= p) {
                    cnt += i / j;
                }

                prefix[i].push_back ( pair<int, int> { p, cnt } );
            }

        }

        for (auto p : primes) {
            int cnt = 0;
            for (int i = p; i <= n; i *= p) {
                cnt += n / i;
            }

            decompsedN[p] = cnt; 
        }
    }

    inline void solve () {
        
        preProcess ();

        int ans = 0;

        for (int i = 1; i <= m; i++) {
            bool flag = true;

            for (auto x : prefix[a[i]]) {
                if (decompsedN[x.first] - x.second < 0) { flag = false; break; }
            }

            if (flag) { 
                ans ++; 
                for (auto x : prefix[a[i]]) { decompsedN[x.first] -= x.second; }
            }
        }

        cout << ans << endl;
    }

}

int main () {

    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    Task1::solve ();

    return 0;
}
