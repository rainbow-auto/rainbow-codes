#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 25;

char a[maxn][maxn];

int n, m;

int main () {

    int T; cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }

        string target = "vika";
        int cur = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[j][i] == target[cur]) {
                    cur++;
                    break;
                }
            }
        }

        cout << (cur == 4 ? "YES" : "NO") << endl;    
    }

    return 0;
}