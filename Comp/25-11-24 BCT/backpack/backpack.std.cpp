#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

namespace PTqwq {

int readqwq() {
    int x = 0;
    bool f = false;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar()) f |= (c == '-');
    for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c - '0');
    if (f) {
        x = -x;
    }
    return x;
}

ll readllqwq() {
    ll x = 0;
    bool f = false;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar()) f |= (c == '-');
    for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c - '0');
    if (f) {
        x = -x;
    }
    return x;
}

const int N = 2e5 + 50;

int n, pos[N];
ll k, valE, a[N], b[N], valx[N];

struct DS {
    vector<ll> info;
    void initT(int siz) {
        info.resize(siz + 1);
        for (auto &x : info) {
            x = 0;
        }
    }
    void upd(ll x, ll y) {
        for (ll i = k; i >= x; -- i) {
            info[i] = max(info[i], info[i - x] + y);
        }
    }
    void upda(int L, int R) {
        for (int i = L; i <= R; ++ i) {
            upd(a[i], valx[i]);
        }
    }
    void updb(int L, int R) {
        for (int i = L; i <= R; ++ i) {
            upd(b[i], valx[i]);
        }
    }
    bool chkT() {
        ll sumT = 0;
        for (auto x : info) {
            sumT += x;
        }
        return (sumT <= valE);
    }
} ds;

void dfs(int L, int R, int qL, int qR) {
    if (L > R) {
        return;
    }
    if (qL == qR) {
        for (int i = L; i <= R; ++ i) {
            pos[i] = qL;
        }
        return;
    }
    int mid = (L + R) / 2;
    DS nowTmp = ds;
    ds.upda(L, mid - 1);
    ds.updb(mid, min(R, qL - 1));
    int cL = max(mid, qL), cR = min(n, qR);
    while (cL <= cR) {
        int cMid = (cL + cR) / 2;
        DS ds2 = ds;
        ds2.updb(cL, cMid);
        ds2.upda(cMid + 1, cR);
        if (ds2.chkT()) {
            ds.upda(cMid, cR);
            cR = cMid - 1;
            pos[mid] = min(pos[mid], cMid);
        } else {
            ds.updb(cL, cMid);
            cL = cMid + 1;
        }
    }
    if (L <= mid - 1) {
        ds = nowTmp;
        ds.upda(pos[mid] + 1, qR);
        ds.updb(mid, min(R, qL - 1));
        dfs(L, mid - 1, qL, pos[mid]);
    }
    if (mid + 1 <= R) {
        ds = nowTmp;
        ds.upda(L, mid);
        ds.updb(max(R + 1, qL), max(mid + 1, pos[mid]) - 1);
        dfs(mid + 1, R, max(mid + 1, pos[mid]), qR);
    }
}

void Solve() {
    n = readqwq();
    k = readllqwq();
    valE = readllqwq();
    valE *= k;
    for (int i = 1; i <= n; ++ i) {
        valx[i] = readllqwq();
        a[i] = readllqwq();
        b[i] = readllqwq();
    }

    for (int i = 1; i <= n; ++ i) {
        pos[i] = n + 1;
    }
    ds.initT(k);
    dfs(1, n, 1, n + 1);

    ll ans = 0;
    for (int i = 1; i <= n; ++ i) {
        if (pos[i] <= n) {
            ll cntI = 1ll * (n - pos[i] + 1);
            ans += cntI;
        }
    }
    printf("%lld\n", ans);
}

}

int main() {
    PTqwq::Solve();

    return 0;
}