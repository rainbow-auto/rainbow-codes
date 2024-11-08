#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

namespace Task1 { // n <= 10, O(n!)
    inline void solve (int n, int k) {
        vector<int> a; for (int i = 1; i <= n; i++) { a.push_back(i); }
        
        int res = 0;
        do {
            bool flag = true;
            for (int i = 0; i < a.size(); i++) {
                if (abs(a[i] - (i + 1)) > k) {
                    flag = false;
                    break;
                }
            }

            if (flag) { res ++; }

        } while (next_permutation(a.begin(), a.end()));
        
        cout << res << endl;
    }
}

int main () {

    int n, k; cin >> n >> k;
    Task1::solve(n, k);

    return 0;
}