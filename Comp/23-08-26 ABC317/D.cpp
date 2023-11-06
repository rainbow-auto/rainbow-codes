#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;

int n;

struct Node {
    double z;
    double w;

    friend bool operator < (Node a, Node b) {
        return (a.w / a.z) < (b.w / b.z);
    }
} a[maxn];


int main () {

    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y >> a[i].z;
        a[i].w = max (0, (y - x + 1) / 2);
        sum += a[i].z;
    }

    sort (a + 1, a + n + 1);

    int limit = (sum + 1) / 2;
    int ans = 0;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += a[i].z;
        ans += a[i].w;

        if (cur >= limit) { break; }
    }

    cout << ans << endl;

    return 0;
}