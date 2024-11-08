#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1005;

int n;
int a[maxn];

int main () {

    cin >> n;

    for (int i = 1; i <= n; i++) { cin >> a[i]; }

    sort (a + 1, a + n + 1);

    for (int i = 2; i <= n; i++) {
        if (a[i] - a[i - 1] > 1) {
            cout << a[i] - 1 << endl;
            return 0;
        }
    }

    return 0;
}