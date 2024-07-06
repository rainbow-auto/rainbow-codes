// 84 pts
// why ???

// 100 pts
// (a xor b) priority

#include <iostream>
#include <map>

using i64 = long long;

int n;

std::map <i64, int> cnt;

int main () {

    std::cin >> n;

    for (int i = 1; i <= n; i ++) {
        i64 a, b; std::cin >> a >> b;

        cnt[a] ++;

        if ((a xor b) != a) { cnt[a xor b] ++; }
    }

    int mxCnt = 0; i64 mxId = (1ll << 50);
    for (auto now : cnt) {
        if (now.second > mxCnt) {
            mxId = now.first;
            mxCnt = now.second;
        } else if (now.second == mxCnt) {
            if (now.first < mxId) {
                mxId = now.first;
                mxCnt = now.second;
            }
        }
    }

    std::cout << mxId << "\n";

    return 0;
}