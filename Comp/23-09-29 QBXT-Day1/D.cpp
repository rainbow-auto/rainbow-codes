#include <iostream>
#include <vector>

using namespace std;

const int maxn = 200005;

int n, m;

struct Query {
    long long a, b;
};

vector <Query> qs;

namespace Task1 {

    struct Info {
        int val, pos;

        friend bool operator < (Info a, Info b) {
            if (a.val != b.val) { return a.val < b.val; }
            else { return a.pos < b.pos; }
        }
    };

    struct Node {
        Info mn;
    } tr[maxn << 3];

    inline void pushUp (int now) {
        tr[now].mn = min (tr[now << 1].mn, tr[now << 1 | 1].mn);
    }

    void build (int now, int l, int r) {
        if (l == r) {
            tr[now].mn = Info { 0, l };
            return;
        }    

        int mid = (l + r) >> 1;

        build (now << 1, l, mid);
        build (now << 1 | 1, mid + 1, r);
        
        pushUp (now);
    }

    void modify (int now, int l, int r, int pos, int val) {
        if (l == r) {
            tr[now].mn.val += val;
            return;
        }

        int mid = (l + r) >> 1;

        if (pos <= mid) { modify (now << 1, l, mid, pos, val); }
        else { modify (now << 1 | 1, mid + 1, r, pos, val); }

        pushUp (now);
    }

    Info query (int now, int l, int r, int L, int R) {
        if (L <= l and r <= R) {
            return tr[now].mn;
        }

        int mid = (l + r) >> 1;

        Info res = Info { 0x3f3f3f3f, n << 1 };

        if (L <= mid) { res = min (res, query (now << 1, l, mid, L, R)); }
        if (R > mid) { res = min (res, query (now << 1 | 1, mid + 1, r, L, R)); }

        return res;
    }

    inline void solve () {
        build (1, 1, n);

        int now = 0;
        for (auto q : qs) {
            for (int i = 1; i <= q.b; i++) {
                int minPos = query (1, 1, n, 1, q.a).pos;
                modify (1, 1, n, minPos, 1);
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << query (1, 1, n, i, i).val << endl;
        }
    }
}

namespace Task2 {

    long long a[maxn];

    inline bool check (int mid, int A, int B) {
        long long sum = 0;
        
        for (int i = 1; i <= A; i++) {
            if (a[i] < mid) {
                sum += mid - a[i];
            }
        }

        return sum <= B;
    }

    inline void solve () {

        for (auto q : qs) {
            long long l = 1, r = 1e12;

            int ans = 0;
            while (l <= r) {
                int mid = (l + r) >> 1;

                if (check (mid, q.a, q.b)) {
                    l = mid + 1;
                    ans = mid;
                } else {
                    r = mid - 1;
                }
            }
            
            cout << "ans = " << ans << endl;

            int sum = 0;
            for (int i = 1; i <= q.a; i++) {
                if (a[i] < ans) { a[i] = ans; sum += ans - a[i]; }
            }

            while (sum < q.b) {
                int minK, minVal = 0x3f3f3f3f;
                for (int i = 1; i <= q.a; i++) { if (a[i] < minVal) { a[i] = minVal; minK = i; } }
                
                a[minK] ++;
                sum ++;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << a[i] << endl;
        }
    }

}

int main () {

    // freopen ("water.in", "r", stdin);
    // freopen ("water.out", "w", stdout);

    int task1Flag = 0;

    cin >> n >> m;

    while (m --) {
        int a, b; cin >> a >> b;
        qs.push_back ( Query { a, b } );
        task1Flag += b;
    }

    // if (task1Flag <= 1000000) {
    //     Task1::solve ();
    // } else {
        Task2::solve ();
    // }

 
    return 0;
}