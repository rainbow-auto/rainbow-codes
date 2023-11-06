#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 7005;

int n, m;
long long s[maxn], v[maxn];

namespace Task1 {
    struct Node {
        long long pos;
        int id;
        friend bool operator < (Node x, Node y) {
            if (x.pos != y.pos) { return x.pos > y.pos; }
            else { return x.id < y.id; }            
        }
    } ns[maxn];

    void solve (long long t, int k) {
        for (int i = 1; i <= n; i++) {
            ns[i].pos = s[i] + t * v[i];
            ns[i].id = i;
        }

        nth_element (ns + 1, ns + k, ns + n + 1);

        cout << ns[k].id << endl;
    }
}

signed main () {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> s[i];
    }

    cin >> m;

    while (m --) {
        long long t; int k; cin >> t >> k;
        
        Task1::solve(t, k);
    }

    return 0;
}