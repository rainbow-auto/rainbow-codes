#include <iostream>
#include <vector>

using namespace std;

const int maxn = 105;

int n;
int c[maxn];
int a[maxn][maxn];

int main () {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        for (int j = 1; j <= c[i]; j++) {
            cin >> a[i][j];
        }
    }
    int x; cin >> x;

    int fewest = 0x3f3f3f3f;

    vector< pair<int, int> > ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c[i]; j++) {
            if (a[i][j] == x) { ans.push_back({i, c[i]}); fewest = min(fewest, c[i]); break; }
        }
    }

    vector<int> endans;
    for (auto i : ans) {
        if (i.second == fewest) { endans.push_back(i.first); }
    }

    cout << endans.size() << endl;
    for (auto i : endans) {
        cout << i << " ";
    } cout << endl;

    return 0;
}