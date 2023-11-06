#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 2005;

int n, m;
int a[maxn][maxn];

int h, w, k;

struct SuffixSum {
    int s[maxn][maxn];
    bool flag;

    inline void preProcess () { // false : 左右 | true : 上下
        if (flag == false) {
            for (int i = 1; i <= n; i++) {
                for (int j = 2; j <= m; j++) {
                    if (a[i][j] != a[i][j - 1]) { s[i][j] = 1; }
                }
            }
        } else { // flag == true
            for (int i = 2; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] != a[i - 1][j]) { s[i][j] = 1; }
                }
            }
        }
    }
    
    inline void init (bool _flag) {
        flag = _flag;
        memset (s, 0, sizeof (s));

        preProcess ();
        // cout << (flag ? "s1 上下" : "s2 左右") << endl;
        // for (int i = flag + 1; i <= n; i++) { for (int j = (not flag) + 1; j <= m; j++) { cout << s[i][j] << " "; } cout << endl; } cout << endl;

        for (int i = flag + 1; i <= n; i++) {
            for (int j = (not flag) + 1; j <= m; j++) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
            }
        }
    }

    inline int sum (int x1, int y1, int x2, int y2) { return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]; }
} s1, s2;

inline bool check (int x, int y) {
    if (h + x - 1 > n) { return false; }
    if (w + y - 1 > m) { return false; }

    // cout << "i = " << x << " j = " << y << endl;
    // cout << "s1 : " << x + 1 << " " << y << " " << h + x - 1 << " " << w + y - 1 << " sum = " << s1.sum (x + 1, y, h + x - 1, w + y - 1) << endl;
    // cout << "s2 : " << x << " " << y + 1 << " " << h + x - 1 << " " << w + y - 1 << " sum = " << s2.sum (x, y + 1, h + x - 1, w + y - 1) << endl;

    return s1.sum (x + 1, y, h + x - 1, w + y - 1) + s2.sum (x, y + 1, h + x - 1, w + y - 1) >= k;
}

int main () {

    cin >> n >> m >> h >> w >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char now; cin >> now;
            if (now == '0') { a[i][j] = 0; }
            else { a[i][j] = 1; }
        }
    }

    s1.init (true); // 上下
    s2.init (false); // 左右

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += check (i, j);
        }
    }

    cout << ans << endl;

    return 0;
}