#include <iostream>

using namespace std;

typedef long long ll;

ll a;

inline void solve () {
    ll ans = 0;
    while (a) {
        ans += a % 60;
        a /= 60;
    }
    cout << ans << endl;
}

int main () {

    cin >> a;

    solve ();

    return 0;
}