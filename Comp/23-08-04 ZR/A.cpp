#include <iostream>
#include <vector>
using namespace std;

const int maxn = 200005;

#define int long long

int n, m;
vector<int> a;

signed main () {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) { a.push_back(i); }
    for (int i = 1; i <= m; i++) { int x; cin >> x; a.push_back(x); }

    int now = 0;
    for (int i = 0; i < a.size(); i++) {
        now ^= a[i];
    }
    
    if (now == 0) { cout << 0 << endl; return 0; }

    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        if ((a[i] ^ now) <= a[i]) {
            ans ++;
        }
    }
    cout << ans << endl;

    return 0;
}