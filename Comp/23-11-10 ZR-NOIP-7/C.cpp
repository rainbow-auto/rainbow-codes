#include <iostream>

using i64 = long long;

const int maxn = 2005;

int T;

int n, m;
int q;

struct Rect {
    int x1, y1;
    int x2, y2;

    friend bool operator < (Rect a, Rect b) {
        if (a.y1 != b.y1) { return a.y1 < b.y1; }
        if (a.x1 != b.x1) { return a.x1 < b.x1; }
    }

} rs[maxn];

namespace Subtask1 {
    
    int dis[maxn][maxn];
    int cnt[maxn][maxn];
    
    inline void solve () {

        for (int i = 1; i <= q; i++) {
            for (int x1 = rs[i].x1; x1 <= rs[i].x2; x1++) {
                for (int y1 = rs[i].y1; y1 <= rs[i].y2; y1++) {
                    for (int x2 = x1 + 1; x2 <= rs[i].x2; x2++) {
                        for (int y2 = y1 + 1; y2 <= rs[i].y2; y2++) {
                            
                        }
                    }
                }
            }
        }
    }  
}

int main () {

    std::cin >> T;

    while (T--) {
        std::cin >> n >> m >> q;

        for (int i = 1; i <= q; i++) {
            std::cin >> rs[i].x1 >> rs[i].y1 >> rs[i].x2 >> rs[i].y2;
        }

        Subtask1::solve ();
    }

    return 0;
}