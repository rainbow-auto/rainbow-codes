#include <iostream>
#include <vector>

using namespace std;

const int maxn = 500005;

int n;
int a[maxn];

namespace Task1 {
    bool dfs () {
        bool res = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0 or a[i + 1] == 0) { continue; }
            if (res == -1) { res = 0; }

            int old1 = a[i], old2 = a[i + 1]; 
            a[i] --; a[i + 1] --; if (i == 1) { a[n + 1] = a[1]; } if (i == n) { a[1] = a[n + 1]; }
            if (dfs ()) { res = 1; }
            a[i] = old1, a[i + 1] = old2; if (i == 1) { a[n + 1] = a[1]; } if (i == n) { a[1] = a[n + 1]; }
        }

        return res == -1 or res == 1;
    }

    void solve () {
        a[n + 1] = a[1];

        cout << (dfs () ? 1 : 0) << endl;
    }
}

namespace Task3 {
    inline void solve () {
        int pos = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) { pos = i; }
        }

        vector<int> v;

        for (int i = pos + 1; i <= n; i++) { v.push_back (a[i]); }
        for (int i = 1; i < pos; i++) { v.push_back (a[i]); }
        v.push_back (0);

        for (int i = 0; i < v.size () - 1; i++) {
            v[i + 1] -= v[i]; if (v[i + 1] < 0) { cout << 0 << endl; return; }
            v[i] -= v[i];
        }
        cout << 1 << endl;
    }
}

int main () {

    int T; cin >> T;

    while (T--) {
        bool Task3Flag = false;
        
        cin >> n;
        for (int i = 1; i <= n; i++) { cin >> a[i]; Task3Flag |= a[i] == 0; }

        if (Task3Flag) { Task3::solve (); }
        else { Task1::solve (); }
    }

    return 0;
}