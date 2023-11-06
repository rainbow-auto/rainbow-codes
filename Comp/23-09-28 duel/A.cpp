#include <iostream>

using namespace std;

const int maxn = 100005;

bool is_prime[maxn];
int prime[maxn], pcnt;

void solve () {
    for (int i = 1; i <= maxn - 5; i++) {
        is_prime[i] = true;
    }

    for (int i = 2; i <= maxn - 5; i++) {
        if (is_prime[i]) {
            prime[++pcnt] = i;
            for (int j = i; j <= maxn - 5; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main () {

    solve ();

    int ans = 0x3f3f3f3f;

    int mxa, mxb, mxc, mxd, mxe, mxf;

    for (int a = 2; a <= 10; a++) {
        for (int b = 2; b <= 10; b++) {
            for (int c = 2; c <= 10; c++) {
                for (int d = 2; d <= 10; d++) {
                    if (prime[c] * prime[d] == prime[a] * prime[b]) { break; }
                    
                    for (int e = 2; e <= 10; e++) {
                        for (int f = 2; f <= 10; f++) {
                            if (prime[e] * prime[f] == prime[c] * prime[d]) { break; }
                        
                            if (ans > prime[a] * prime[b] + prime[c] * prime[d] + prime[e] * prime[f]) {
                                mxa = a, mxb = b, mxc = c, mxd = d, mxe = e, mxf = f;
                                ans = prime[a] * prime[b] + prime[c] * prime[d] + prime[e] * prime[f];
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;

    cout << mxa << " " << mxb << " " << mxc << " " << mxd << " " << mxe << " " << mxf << endl;

    // int n;
    // cin >> n;

    // for (int i = 1; i <= n; i++) {
    //     int now; cin >> now;
    //     if (now > 33) { cout << "Yes" << endl; }
    //     else { cout << "No" << endl; }
    // }

    return 0;
}