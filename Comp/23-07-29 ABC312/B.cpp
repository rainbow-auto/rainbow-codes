#include <iostream>
#include <string>

using namespace std;

const int maxn = 105;

int n, m;
int mp[maxn][maxn];

int main () {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char now; cin >> now;
            mp[i][j] = now == '#'; // 1: 黑, 2: 白
        }
    }

    for (int x1 = 1; x1 + 9 - 1 <= n; x1++) {
        for (int y1 = 1; y1 + 9 - 1 <= m; y1++) {

            // 黑色

            bool flag1 = true;
            
            flag1 = flag1 and mp[x1][y1] and mp[x1 + 1][y1] and mp[x1 + 2][y1];
            flag1 = flag1 and mp[x1][y1 + 1] and mp[x1 + 1][y1 + 1] and mp[x1 + 2][y1 + 1];
            flag1 = flag1 and mp[x1][y1 + 2] and mp[x1 + 1][y1 + 2] and mp[x1 + 1][y1 + 2];

            int tx1, ty1;
            
            tx1 = x1, ty1 = y1;
            x1 = x1 + 6;
            y1 = y1 + 6;
            
            flag1 = flag1 and mp[x1][y1] and mp[x1 + 1][y1] and mp[x1 + 2][y1];
            flag1 = flag1 and mp[x1][y1 + 1] and mp[x1 + 1][y1 + 1] and mp[x1 + 2][y1 + 1];
            flag1 = flag1 and mp[x1][y1 + 2] and mp[x1 + 1][y1 + 2] and mp[x1 + 1][y1 + 2];

            x1 = tx1, y1 = ty1;

            // 白色
            bool flag2 = false;

            flag2 = flag2 or mp[x1 + 3][y1 + 3];
            flag2 = flag2 or mp[x1 + 3][y1] or mp[x1 + 3][y1 + 1] or mp[x1 + 3][y1 + 2];
            flag2 = flag2 or mp[x1][y1 + 3] or mp[x1 + 1][y1 + 3] or mp[x1 + 2][y1 + 3];

            tx1 = x1, ty1 = y1;
            x1 = x1 + 5;
            y1 = y1 + 5;
            
            flag2 = flag2 or mp[x1][y1];
            flag2 = flag2 or mp[x1 + 1][y1] or mp[x1 + 2][y1] or mp[x1 + 3][y1];
            flag2 = flag2 or mp[x1][y1 + 1] or mp[x1][y1 + 2] or mp[x1][y1 + 3];

            x1 = tx1, y1 = ty1;

            if (flag1 and not flag2) {
                cout << x1 << " " << y1 << endl;
            }
        }
    }

    return 0;
}