#include <iostream>

using namespace std;

const int maxn = 2005;

int n;
int a[maxn];

int dp[maxn];

int main () {

    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] >= a[j]) { dp[i] = std::max (dp[i], dp[j] + 1); }
        }
    }

    for (int i = 1; i <= n; i++) {
        int dp1max = 0;
        int dp0max = 0;
        for (int j = n; j >= i; j--) {
            if (a[j] == 0) {  }
        }
        
        for (int j = 1; j < i; j++) {
            if (a[j] == 1)
        }
    }

    return 0;
}