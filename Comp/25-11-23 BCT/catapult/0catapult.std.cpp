#include <bits/stdc++.h>

#define long long long int
#define DEBUG
#define db std::cerr
using namespace std;

// @author: pashka

vector<vector<int>> g;
vector<vector<int>> g2;

vector<int> z;
vector<int> p;

bool dfs(int x, int ex) {
    db << "x: " << x << "\n";
    z[x] = 1;
    for (int y: g[x]) {
        if (z[y] == 1) return false;
        if (z[y] == 0) {
            if (!dfs(y, ex)) {
                return false;
            }
        }
    }
    z[x] = 2;
    db << "pushback " << x << "\n";
    p.push_back(x);
    return true;
}

bool is_acyclic(vector<int> c, int ex) {
    for (int x: c) z[x] = 0;
    for (int x : c) db << x << " "; db << "\n";
    p.clear();
    for (int x: c) {
        if (z[x] == 0) {
            db << "dfs " << x << "\n";
            if (!dfs(x, ex)) return false;
        }
    }
    return true;
}

vector<bool> z2;
vector<int> p2;

void dfs2(int x) {
    if (z2[x]) return;
    z2[x] = true;
    for (int y: g2[x]) {
        dfs2(y);
    }
    p2.push_back(x);
}

int main() {
//	freopen("catapult.in","r",stdin);
//	freopen("catapult.out","w",stdout);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    g.resize(n);
    g2.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[b].push_back(a);
        g2[a].push_back(b);
        g2[b].push_back(a);
    }

    vector<pair<int, int>> res;
    z.resize(n);
    z2.resize(n);
    for (int i = 0; i < n; i++) {
        if (z2[i]) continue;
        p2.clear();
        dfs2(i);

        if (is_acyclic(p2, -1)) {
            int k = p.size();
            for (int j = 0; j < k - 1; j++) {
                res.push_back({p[j], p[j + 1]});
            }
        } else {
            bool ok = false;
            for (int ex: p2) {
                if (is_acyclic(p2, ex)) {
                    p.push_back(ex);
                    int k = p.size();
                    res.push_back({p[k - 1], p[0]});
                    for (int j = 0; j < k - 1; j++) {
                        res.push_back({p[j], p[j + 1]});
                    }
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << res.size() << "\n";
    for (auto p : res) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }

    return 0;
}