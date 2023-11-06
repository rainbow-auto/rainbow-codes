#include <iostream>

using namespace std;

const int maxn = 200005;

int n;
int a[maxn];

namespace Task1 {

    inline void solve () {

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if ((a[i] - a[j]) % 200 == 0) {
                    ans ++;
                }  
            }
        }

        cout << ans << endl;
    }
}

int main () {
    
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    Task1::solve ();

    return 0;
}