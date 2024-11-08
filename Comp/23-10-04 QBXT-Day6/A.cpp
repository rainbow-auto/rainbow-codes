#include <iostream>
#include <vector>

using namespace std;

const int N = 1e9;
const int maxn = 1e7 + 10;
unsigned int x = 123456789, y = 362436069, z, a[maxn];
int n, q;
unsigned int gen()
{
    unsigned int t;
    x ^= x << 16; x ^= x >> 5; x ^= x << 1;
    t = x; x = y; y = z; z = t ^ x ^ y;
    return z % N + 1;
}

struct Query {
    int l, r;
};
vector<Query> qs;

namespace Task1 {

    struct Node {
        long long sum;
        bool cov;
    } tr[maxn << 2];

    void build (int now, int l, int r) {
        if (l == r) {
            tr[now].sum = a[l];
            return;
        }

        int mid = (l + r) >> 1;
        build (now << 1, l, mid);
        build (now << 1 | 1, mid + 1, r);

        tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
    }      

    inline void pushDown (int now) {
        if (not tr[now].cov) { return; }
        tr[now << 1].sum = 0; tr[now << 1].cov = true;
        tr[now << 1 | 1].sum = 0; tr[now << 1 | 1].cov = true;
    }

    void modify (int now, int l, int r, int L, int R) {
        if (L <= l and r <= R) {
            tr[now].sum = 0;
            tr[now].cov = true;
            return;
        }

        pushDown (now);

        int mid = (l + r) >> 1;
        if (L <= mid and tr[now << 1].sum) { modify (now << 1, l, mid, L, R); }
        if (R > mid and tr[now << 1 | 1].sum) { modify (now << 1 | 1, mid + 1, r, L, R); }
    
        tr[now].sum = tr[now << 1].sum + tr[now << 1 | 1].sum;
    }

    long long query (int now, int l, int r, int L, int R) {
        if (L <= l and r <= R) { return tr[now].sum; }
        
        pushDown (now);
        
        int mid = (l + r) >> 1;
        long long res = 0;
        if (L <= mid and tr[now << 1].sum) { res += query (now << 1, l, mid, L, R); }
        if (R > mid and tr[now << 1 | 1].sum) { res += query (now << 1 | 1, mid + 1, r, L, R); }
        return res;
    }

    inline void solve () {
        build (1, 1, n);

        long long res = 0;
        for (auto now : qs) {
            res ^= query (1, 1, n, now.l, now.r);
            modify (1, 1, n, now.l, now.r);
        }

        cout << res << endl;
    }
}

int main()
{
    scanf("%d%d%u", &n, &q, &z);
    for ( int i = 1; i <= n; ++ i ) 
        a[i] = gen();

    for ( int i = 1; i <= q; ++ i ) 
    {
        int l = gen() % n + 1, r = gen() % n + 1;
        if ( l > r ) swap(l, r);
        qs.push_back ( Query { l, r } );
    }

    Task1::solve ();

    return 0;
}