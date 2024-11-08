#include <iostream>

using namespace std;

const int maxn = 105;

int n, h, x;
int p[maxn];

int main () {

    cin >> n >> h >> x;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        if (h + p[i] >= x) { cout << i << endl; return 0; } 
    }

    return 0;
}