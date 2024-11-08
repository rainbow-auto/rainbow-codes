#include <iostream>
#include <vector>

using namespace std;

const int maxn = 200005;

#define endl "\n"

int n, q;

struct Query {
    long long a, b;
};

vector<Query> qs;

namespace Solution {

    struct Node {
        long long sum;
        long long tag; bool cov;
    } tr[maxn << 4];

    void build (int now, int l, int r) {
        if (l == r) {
            tr[now].sum = 0ll;
            tr[now].tag = 0ll; tr[now].cov = false;
            return ;
        }

        int mid = (l + r) >> 1;

        build (now << 1, l, mid);
        build (now << 1 | 1, mid + 1, r);

        tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
    }

    inline void update (int now, int l, int r, long long val) {
        tr[now].sum = (long long) (r - l + 1) * val;
        tr[now].cov = true; tr[now].tag = val;
    }

    inline void pushDown (int now, int l, int r) {
        if (not tr[now].cov) { return ; }

        int mid = (l + r) >> 1;
        update (now << 1, l, mid, tr[now].tag);
        update (now << 1 | 1, mid + 1, r, tr[now].tag);
        tr[now].cov = false; tr[now].tag = 0ll;
    }

    void modify (int now, int l, int r, int L, int R, long long val) {
        if (L > R) { return; }
        
        if (L <= l and r <= R) {
            update (now, l, r, val);
            return ;
        }

        int mid = (l + r) >> 1;

        pushDown (now, l, r);

        if (L <= mid) { modify (now << 1, l, mid, L, R, val); }
        if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, val); }

        tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
    }

    long long query (int now, int l, int r, int L, int R) {
        if (L <= l and r <= R) {
            return tr[now].sum;
        }

        int mid = (l + r) >> 1;

        pushDown (now, l, r);

        long long res = 0;
        if (L <= mid) { res += query (now << 1, l, mid, L, R); }
        if (R > mid) { res += query (now << 1 | 1, mid + 1, r, L, R); }

        return res;
    }

    // inline void display () { for (int i = 1; i <= n; i++) { cout << query (1, 1, n, i, i) << " "; } cout << endl; }

    inline void solve () {

        build (1, 1, n);

        int now = 0;

        for (auto q : qs) {

            // 1

            int l = 1, r = q.a;

            int res1 = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;

                long long midVal = query (1, 1, n, mid, mid);

                if ( (q.a - mid + 1) * midVal - query (1, 1, n, mid, q.a) <= q.b ) {
                    r = mid - 1;
                    res1 = mid;
                } else {
                    l = mid + 1;
                }
            }

            long long val = query (1, 1, n, res1, res1); // 平推的值
            long long sum = (long long) (q.a - res1 + 1) * val - query (1, 1, n, res1, q.a);

            modify (1, 1, n, res1, q.a, val);

            // display ();

            // 2            

            long long rest = q.b - sum; // 没有填完的
            
            if (rest <= 0) { continue; }

            val += rest / (long long)(q.a - res1 + 1);
            modify (1, 1, n, res1, q.a, val);
            
            modify (1, 1, n, res1, res1 + rest % (long long)(q.a - res1 + 1) - 1, val + 1);
        }

        for (int i = 1; i <= n; i++) {
            cout << query (1, 1, n, i, i) << endl;
        }

    }   

}

int main () {

    freopen ("water.in", "r", stdin);
    freopen ("water.out", "w", stdout);

    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    cin >> n >> q;

    while (q--) {
        long long a, b; cin >> a >> b;
        qs.push_back ( Query { a, b } );
    }

    Solution::solve ();

    return 0;
}