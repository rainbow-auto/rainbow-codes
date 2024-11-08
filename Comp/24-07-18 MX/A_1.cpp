#include <iostream>

const int maxn = 100005;

int n, m, b;

std::string s[maxn];

namespace Task1 {
    
    int pos[25];

    const int maxS = (1 << 18);

    std::string inf = "ZZZZZZZZZZZZZZZZZZZZ";

    std::string mem[maxS];
    std::string dp (int S) {
        if (mem[S] != "") { return mem[S]; }

        int curr = 0;
        for (int i = 1; i <= n; i++) {
            if (S & (1 << (i - 1))) {
                curr += s[i].size ();
                curr %= m;
            }
        }

        std::string res = inf;

        for (int i = 1; i <= n; i++) {
            if (S & (1 << (i - 1))) {
                if (pos[i] == (curr - b + 1 + m) % m or pos[i] == -1) {
                    res = std::min (res, dp (S ^ (1 << (i - 1))) + std::to_string ('0' + i - 1));
                }
            }
        }

        mem[S] = res;
        
        return res;
    }   
    
    inline void solve () {
        for (int i = 1; i <= n; i++) {
            int p = 0;
            for (int j = s[i].size () - 1; j >= 0; j--) {
                p ++;
                if (s[i][j] == '1') { pos[i] = p; goto nxt; }
            }
            
            pos[i] = -1;
            nxt: continue;
        }

        std::cout << dp ((1 << n) - 1) << "\n";
    }
}

int main () {

    std::cin >> n >> m >> b;

    for (int i = 1; i <= n; i++) { std::cin >> s[i]; }

    Task1::solve ();

    return 0;
}