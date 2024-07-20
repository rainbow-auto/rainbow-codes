#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

#pragma gcc optimize ("Ofast")

using i64 = long long;

const int maxn = 15;

int n, k;

std::string s;

int ord[maxn];

using namespace __gnu_pbds;

gp_hash_table <std::string, int> ans;

inline bool chk () {
    for (int i = 0; i <= n - k; i++) {
        bool flag = true;

        for (int j = 1; j <= k; j++) {
            flag &= (s[ord[i + j]] == s[ord[i + k + 1 - j]]);
        }

        if (flag) { return false; }
    }

    return true;
}

int main () {

    std::cin >> n >> k;
    std::cin >> s;
    s = " " + s;

    for (int i = 1; i <= n; i++) { ord[i] = i; }

    do {
        std::string curr;
        for (int i = 1; i <= n; i++) { curr = curr + s[ord[i]]; }   

        if (chk ()) {
            ans[curr] ++;
        }

    } while (std::next_permutation (ord + 1, ord + n + 1));

    std::cout << ans.size () << "\n";

    return 0;
}