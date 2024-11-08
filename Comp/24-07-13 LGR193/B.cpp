#include <iostream>
#include <string>

using i64 = long long;

const int maxn = 500005;

int n;

std::string s, t;

int op[maxn];

int main () {

    int T; std::cin >> T;

    while (T--) {
        s = ""; t = "";

        std::cin >> s;
        std::cin >> t;
        n = s.size ();

        s = " " + s; t = " " + t;

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == t[i]) { op[i] = s[i] - '0'; }
            else if (s[i] == '0') { op[i] = 3; ans ++; } // X
            else if (s[i] == '1') { op[i] = 4; ans ++; } // Y
        }

        bool flagX = false;
        bool flagY = false;

        for (int i = 1; i <= n; i++) {
            if (op[i] == 0 or op[i] == 4) { flagX = false; }
            if (op[i] == 1 or op[i] == 3) { flagY = false; }

            if ((op[i] == 3 or op[i] == 4) and (op[i - 1] == 3 or op[i - 1] == 4)) { ans --; }
            else {
                if (flagX and op[i] == 3) { ans --; }
                if (flagY and op[i] == 4) { ans --; }
            
                if (op[i] == 3) { flagX = true; }
                if (op[i] == 4) { flagY = true; }
            }
        }

        std::cout << ans << "\n";
    }

    return 0;
}