#include <iostream>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng (std::chrono::steady_clock::now().time_since_epoch ().count ());

inline int getNum (int l, int r) {
    return std::uniform_int_distribution<int> (l, r) (rng);
}

const int maxn = 1000005;

std::set<int> s;
int cnt[maxn];

int main () {

    int n = 100;
    int q = 100;

    std::cout << n << " " << q << "\n";

    for (int i = 1; i <= n; i++) {
        int x = getNum (1, n); std::cout << x << " ";
        cnt[x] ++;
    }

    std::cout << "\n";

    int rest = n;

    while (q--) {
        int op = getNum (1, 3); std::cout << op << " ";
        if (op == 1) { 
            int x = getNum (1, n);
            std::cout << x << "\n"; 

            if (cnt[x] == 0) { s.insert (x); } 
            cnt[x] ++;  
            rest ++;
        }
        if (op == 2) {
            int rnk = getNum (1, s.size ());

            int x;
            int i = 1; for (auto now : s) { if (i == rnk) { x = now; break; } i++; }
            std::cout << x << "\n";

            if (cnt[x] == 1) { s.erase (x); }
            cnt[x] --;
            rest --;
        }
        if (op == 3) { 
            std::cout << getNum (1, rest) << "\n"; 
        }
    }

    return 0;
}