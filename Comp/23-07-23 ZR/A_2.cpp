#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 25005;

int n, q;
bool g[maxn][maxn];
vector<int> g2[maxn];

bool s[maxn];
int s2[maxn];

int main () {

    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
        g2[u].push_back (v);
        g2[v].push_back (u);
    } 

    cin >> q;

    while (q--) {
        int s_siz; cin >> s_siz;

        memset (s, 0, sizeof (s));
        for (int i = 1; i <= s_siz; i++) {
            int now; cin >> now;
            s[now] = true;
            s2[i] = now;
        }

        if (s_siz == 2) {
            if (g[s[1]][s[2]]) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        } else {
            int cnt = 0;
            for (int i = 1; i <= s_siz; i++) {
                for (int j = 0; j < g2[i].size(); i++) {
                    int t = g2[i][j];
                    if (s[t]) {
                        cnt ++;
                    } 
                }
            }

            cout << cnt / 2 << endl;
        }

    }    

    return 0;
}