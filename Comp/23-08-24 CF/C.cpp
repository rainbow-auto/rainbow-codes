#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 200005;

int n;
int a[maxn];
int b[maxn]; // 翻转过后的a

int main () {

    int T; cin >> T;

    while (T--) {
        memset (a, 0, sizeof (a));
        memset (b, 0, sizeof (b));
        
        cin >> n;
        
        int maxA = 0;
        for (int i = 1; i <= n; i++) { cin >> a[i]; maxA = max (a[i], maxA); }
        
        if (maxA > n) { cout << "NO" << endl; continue; }

        for (int i = 1; i <= n; i++) {
            b[1] ++;
            b[a[i] + 1] --;
        }
        for (int i = 1; i <= n; i++) { b[i] += b[i - 1]; }

        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) { flag = false; cout << "NO" << endl; break; }
        }
        if (flag) { cout << "YES" << endl; }
    }

    return 0;
}