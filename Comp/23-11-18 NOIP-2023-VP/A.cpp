#include <iostream>
#include <string>
#include <algorithm>

using i64 = long long;

int n, m;

namespace Subtask1 {

    const int maxn = 30;

    char w[maxn];    

    inline void solve () {
        for (int i = 1; i <= n; i++) {
            std::cin >> w[i];
        }

        for (int i = 1; i <= n; i++) {
            bool flag = false;
            for (int j = 1; j <= n; j++) {
                if (j == i) { continue; }

                if (w[j] < w[i]) { flag = true; std::cout << 0; break; }
            }

            if (not flag) { std::cout << 1; }
        }
    }
}

namespace Subtask2 {
    const int maxn = 20;

    struct Word {
        char first, second;

        friend bool operator < (Word x, Word y) {
            if (x.first != y.first) { return x.first < y.first; }
            else { return x.second < y.second; }
        }
    };

    Word w[maxn];
    Word w_max[maxn];
    Word w_min[maxn];

    inline void solve () {
        for (int i = 1; i <= n; i++) {
            std::cin >> w[i].first >> w[i].second;
        }

        for (int i = 1; i <= n; i++) {
            if (w[i].first > w[i].second) {
                w_max[i] = Word { w[i].first, w[i].second };
                w_min[i] = Word { w[i].second, w[i].first };
            } else {
                w_max[i] = Word { w[i].second, w[i].first };
                w_min[i] = Word { w[i].first, w[i].second };
            }
        }

        for (int i = 1; i <= n; i++) {
            bool flag = false;
            for (int j = 1; j <= n; j++) {
                if (j == i) { continue; } 

                if (w_max[j] < w_min[i]) { flag = true; std::cout << 0; break; }
            }

            if (not flag) { std::cout << 1; }
        }
    }

}

namespace Solution {

    const int maxn = 3005;

    std::string w[maxn];

    int w_min[maxn];
    int w_max[maxn];

    struct Word {
        std::string word;
        int id;
        int flag;
        /*
            flag:
            1: w_min
            2: w_max
        */

        friend bool operator < (Word a, Word b) {
            return a.word < b.word;
        }

        friend bool operator == (Word a, Word b) {
            return a.word == b.word;
        }
    };

    Word words[maxn * 2];
    int tot = 0;

    inline void get_rank () {
        for (int i = 1; i <= n; i++) { 
            std::sort (w[i].begin (), w[i].end (), [] (char a, char b) { return a < b; } );
            words[++tot] = Word { w[i], i, 1 };
        }

        for (int i = 1; i <= n; i++) { 
            std::sort (w[i].begin (), w[i].end (), [] (char a, char b) { return a > b; } );
            words[++tot] = Word { w[i], i, 2 };
        }

        std::sort (words + 1, words + tot + 1);

        int rank_now = 0;
        for (int i = 1; i <= tot; i++) {
            if (i == 1 or not (words[i] == words[i - 1])) { rank_now ++; }
            
            if (words[i].flag == 1) { w_min[words[i].id] = rank_now; }
            if (words[i].flag == 2) { w_max[words[i].id] = rank_now; }
        }
    }

    inline void solve () {
        
        for (int i = 1; i <= n; i++) {
            std::cin >> w[i];
        }
        
        get_rank ();

        for (int i = 1; i <= n; i++) {
            bool flag = false;
            for (int j = 1; j <= n; j++) {
                if (j == i) { continue; }

                if (w_max[j] < w_min[i]) { flag = true; std::cout << 0; break; }
            }

            if (not flag) { std::cout << 1; }
        }
    }
}

int main () {

    std::cin >> n >> m;

    if (n == 1) { std::cout << 1; return 0; }
    
    if (m == 1) { Subtask1::solve (); return 0; }
    if (m == 2) { Subtask2::solve (); return 0; }
    
    Solution::solve ();

    return 0;
}