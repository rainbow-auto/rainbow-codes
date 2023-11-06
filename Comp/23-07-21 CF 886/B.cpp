#include <iostream>

using namespace std;

int T;
int n;

int main () {
    cin >> T;

    while (T--) {
        int n; cin >> n;
        
        int ans_val = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            int a, b; cin >> a >> b;
            
            if (a <= 10) {
                if (ans_val < b) {
                    ans_val = b;
                    ans = i;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}