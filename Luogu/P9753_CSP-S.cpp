#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

typedef unsigned long long i64;

template <typename val_t>
inline void read (val_t &res) {
    res = 0;
    int flag = 1;
    char ch = getchar ();

    while (not isdigit (ch)) { if (ch == '-') { flag = -1; } ch = getchar (); }
    while (isdigit (ch)) { res = res * 10 + ch - '0'; ch = getchar (); }

    res *= flag;   
}

const int maxn = 4000005;

int n;
char s[maxn];

namespace Subtask2 {
    // int len[maxn];
	int lpos[maxn];

    i64 f[maxn];

    inline void solve () {
        i64 ans = 0;

        for (int i = 1; i <= n; i++) {
            int l = i + 1, r = i;
            
            while (l - 1 >= 1 and r + 1 <= n and s[l - 1] == s[r + 1]) {
                l --; r ++;
				lpos[r] = std::max (lpos[r], l);
			}
        }  
	
        for (int i = 1; i <= n; i++) {
                // int l = i - len[i] + 1;
                // int r = i + len[i];
                // f[r] = f[l - 1] + 1;

				if (lpos[i] == 0) { continue; }
				f[i] = f[lpos[i] - 1] + 1;

                // std::cerr << "f " << r << " += " << f[l - 1] << "\n";
        }
		
		// for (int i = 1; i <= n; i++) {
		// 	std::cerr << f[i] << " ";
		// }
		// std::cerr << "\n";

		// for (int i = 1; i <= n; i++) {
		// 	std::cerr << lpos[i] << " ";
		// }
        
        // for (int i = 1; i <= n; i++) {
        //     std::cerr << len[i] << " ";
        // }
        // std::cerr << "\n";

        for (int i = 1; i <= n; i++) {
        	ans += f[i];
            // std::cerr << f[i] << " ";
		}
        // std::cerr << "\n";

        std::cout << ans << "\n";
    }
}

namespace Subtask1 {
	int lpos[maxn];
	i64 f[maxn];

	inline void solve () {
		
		for (int i = 2; i <= n; i++) {
			int pos = i - 1;

			while (pos > 0 and s[pos] != s[i]) { pos = lpos[pos] - 1; }
			lpos[i] = std::max (pos, 0);
		}		

		for (int i = 1; i <= n; i++) {
			if (lpos[i] > 0) { f[i] = f[lpos[i] - 1] + 1; }
		}

		i64 ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += f[i];
		}

		std::cout << ans << "\n";
	}

}

int main () {

    // freopen ("game.in", "r", stdin);
    // freopen ("game.out", "w", stdout);

    read (n);
    std::cin >> (s + 1);

    // Subtask2::solve ();
	Subtask1::solve ();

    return 0;
}