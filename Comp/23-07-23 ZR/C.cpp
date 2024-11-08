#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 150005;

int n;
int a[maxn];

namespace Task1 {
    int tr[maxn];

    inline int lowbit (int x) {return x & (-x);}
    inline void add (int pos, int val) {for (int i = pos; i <= n; i += lowbit(i)) tr[i] += val;}
    inline int query (int pos) {int res = 0; for (int i = pos; i; i -= lowbit(i)) res += tr[i]; return res;}

    void solve () {
        memset (tr, 0, sizeof (tr));
        int ans = 0;
       
        for (int j = 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                for (int l = k + 1; l <= n; l++) {
                    if (a[k] < a[j] and a[j] < a[l]) {
                        ans += query (a[k]);
                    }
                }
            }
            add (a[j], 1);
        }

        cout << ans;
    }        
}

int main () {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    Task1::solve();

    return 0;
}
