#include <iostream>

using namespace std;

const int maxn = 1005;

int T;

char c[maxn][maxn];

int main () {

    cin >> T;

    while (T--) {
        for (int i = 1; i <= 8; i ++) {
            for (int j = 1; j <= 8; j++) {
                cin >> c[i][j];
            }
        }

        string s = "";
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                if (c[i][j] != '.') {
                    s = s + c[i][j];
                }
            }
        }

        cout << s << endl;
    }

    return 0;
}