#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 10000005;

int n;
int p[maxn];

namespace Gen {
    long long a[maxn];
    inline void gen () {
        const long long mod1 = 998244353;
        const long long mod2 = 1e9 + 7;
        const long long mod3 = 1e9 + 9;

        cin >> n >> a[0];
        for (int i = 1; i <= n; i++) {
            a[i]= (a[i - 1] * mod1 + mod2) % mod3;
            p[i] = i;
        }

        for (int i = 1; i <= n; i++) {
            swap (p[i], p[a[i] % i + 1]);
        }
    }
}

namespace Task1 {
    int ans[maxn];
    inline void solve () {
        for (int i = 1; i <= n; i++) {
            int rnk = (i + 1) >> 1;
            nth_element (p + 1, p + rnk, p + i + 1);
            ans[i] = p[rnk];   
        }

        const int mod = 998244353;

        int output = 0;
        int now = 1;
        for (int i = 1; i <= n; i++) { output += ((now * 19) % mod * ans[i]) % mod; output %= mod; now *= 19; now %= mod; }
        cout << output << endl;
    }
}

namespace Task2 {
    struct Node {
        int l, r;
        int val, key, size;
    };

    Node fhq[maxn];
    int cnt, root;

    inline int newNode (int val) {
        cnt ++;
        fhq[cnt].val = val;
        fhq[cnt].key = rand();
        fhq[cnt].size = 1;
        return cnt;	
    }

    inline void update (int x) {
        fhq[x].size = fhq[fhq[x].l].size + fhq[fhq[x].r].size + 1;
    }

    void split (int now, int val, int& x, int& y) { // x <= val y > val
        if (not now) {
            x = y = 0;
        } else if (fhq[now].val > val) { 
            y = now; // now 和 它的右子树都一定 > val
            split (fhq[now].l, val, x, fhq[now].l); // 左小右大
            update (now);
        } else {
            x = now; // now 和 它的左子树都一定 <= val
            split (fhq[now].r, val, fhq[now].r, y); // 左小右大
            update (now);
        }
    }

    int merge (int x, int y) { // 把 y 合并到 x 上 (x 小 y 大)
        if (not x or not y) {
            return x | y; // 有一个是零, 因此加/或起来的一定是那个不为0的
        } else if (fhq[x].key < fhq[y].key) { // 考虑维护key是堆的性质
            fhq[x].r = merge (fhq[x].r, y); // x 放在上面
            update (x);
            return x;
        } else {
            fhq[y].l = merge (x, fhq[y].l); // y 放在上面
            update (y);
            return y;
        }
    }

    inline void insert (int val) {
        int x, y;
        split (root, val, x, y); // x: <= val
        x = merge (x, newNode(val));
        root = merge (x, y);
    }

    inline int get_num (int rank) {
        int now = root;
        while (now) {
            if (fhq[fhq[now].l].size + 1 == rank) {return fhq[now].val;}
            else if (fhq[fhq[now].l].size >= rank) {now = fhq[now].l;}
            else {rank -= fhq[fhq[now].l].size + 1; now = fhq[now].r;}
        }
        return -1; // 不存在
    }

    int ans[maxn];
    inline void solve () {
        for (int i = 1; i <= n; i++) {
            insert (p[i]);
            ans[i] = get_num ((i + 1) >> 1);
        }

        const int mod = 998244353;

        long long output = 0;
        long long now = 1;
        for (int i = 1; i <= n; i++) { output += ((now * 19) % mod * ans[i]) % mod; output %= mod; now *= 19; now %= mod; }
        cout << output << endl;
    }
}

int main () {

    Gen::gen ();
    Task2::solve ();

    return 0;
}