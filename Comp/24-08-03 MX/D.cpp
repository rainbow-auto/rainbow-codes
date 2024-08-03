#include <iostream>

const int maxn = 20;

namespace Solution {

    struct Matrix {
        int a[maxn][maxn];

        Matrix () {
            memset (a, 0x3f, sizeof (a));
        }

        friend Matrix operator * (Matrix x, Matrix y) {
            Matrix res;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    for (int k = 1; k <= n; k++) {
                        res.a[i][j] = std::min (res.a[i][j], x.a[i][k] + y.a[k][j]);
                    }   
                }
            }
            
        }
    };
}

int main () {

    return 0;
}