#include <iostream>

using namespace std;

typedef unsigned long long ll;

const ll mod = 998244353;

int main () {

    int n; cin >> n;
    if (n == 1) {
        ll p; cin >> p;
        cout << (p % mod * p % mod) % mod << endl; 
    } else {
        ll p1, p2; cin >> p1 >> p2;
        ll a[5];
        a[1] = 0;
        a[2] = p1;
        a[3] = p2;
        a[4] = (p1 % mod * p2 % mod) % mod;
        for (int i = 1; i)
    }


    return 0;
}