#include <iostream>
#include <cstring>
#include <map>

using namespace std;

namespace Task1 {
    const int maxn = 10005;
    int mem[maxn];
    
    int f (int x) {
        if (mem[x]) { return mem[x]; }
        if (x < 10) { mem[x] = x * x; return mem[x]; }
        mem[x] = f (x / 10) + (x % 10) * (x % 10); return mem[x];
    }

    int solve (int l, int r, int k) {
        int res = 0;
        for (int i = l; i <= r; i++) {
            if (f(i) * k == i) { res ++; }
        }
        return res;
    }
}

#define int __int128

inline void read (int& x) {
    char ch = getchar();
    x = 0;

    while (not isdigit(ch)) { ch = getchar(); }
    while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
}

inline void print (int x) {
    if (not (x / 10)) { cout << (long long)x; }
    else { print(x / 10); cout << (long long)(x % 10); }
}

int T;
int l, r, k;
int a[25], len;

int mem[25][9 * 9 * 25]; // 有了num, sum唯一确定 (num 1e18)
int dfs (int now, int num, int sum, bool limit) { // 似乎不用维护前导零
    if (now > len) {
        if (sum * k == num) {
            return 1;
        } else {
            return 0;
        }
    }

    if (not limit and mem[now][sum] != -1) { return mem[now][sum]; }

    int ret = 0;

    int mx = limit ? a[len - now + 1] : 9;
    for (int i = 0; i <= mx; i++) {
        ret += dfs (now + 1, num * 10 + i, sum + i * i, limit and i == mx);
    }

    if (not limit) { mem[now][num] = ret; }

    return ret;
}

int solve (int x) {
    len = 0; memset (a, 0, sizeof(a)); memset (mem, -1, sizeof(mem));
    while (x) {
        a[++len] = x % 10;
        x /= 10;
    }
    return dfs (1, 0, 0, true);
}

signed main () {

    read(k); read(l); read(r);
    if (solve(r) - solve(l - 1) != Task1::solve(l, r, k)) return 114514;
	
    return 0;
}
