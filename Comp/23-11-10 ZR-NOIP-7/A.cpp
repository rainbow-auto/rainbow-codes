#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")

#include <iostream>
#include <string>
#include <vector>

using i64 = long long;

const int maxn = 15;

std::string s;

int n;
int a[maxn];

namespace Subtask2 {

    int ans = 0;

    std::vector<int> vec;

    void dfs (int now) {
        for (int i = 0; i < (int) vec.size () - 1; i++) {
            int sum = vec[i] + vec[i + 1];

            if (sum >= 10) {
                int old_1 = vec[i];
                int old_2 = vec[i + 1];

                vec[i] = sum / 10;
                vec[i + 1] = sum % 10;

                ans = std::max (ans, now + 1);
                dfs (now + 1);

                vec[i] = old_1;
                vec[i + 1] = old_2;
            
            } else {
                int old_1 = vec[i];
                int old_2 = vec[i + 1];

                vec[i + 1] = sum;
                vec.erase (vec.begin () + i);

                ans = std::max (ans, now + 1);
                dfs (now + 1);

                vec.insert (vec.begin () + i, old_1);
                vec[i + 1] = old_2;
            }
        }   
    }

    inline void solve () {
        n = s.size ();
        for (auto c : s) { vec.push_back (c - '0'); }

        dfs (0);

        std::cout << ans << "\n";
    }
}

int main () {

    std::cin >> s;

    Subtask2::solve ();

    return 0;
}