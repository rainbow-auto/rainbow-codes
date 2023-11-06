#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 200005;

int n;
int b[maxn];

int main () {

    int T; cin >> T;

    while (T--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        vector<int> a;

        a.push_back (b[1]);
        for (int i = 2; i <= n; i++) {
            if (b[i] < b[i - 1]) { a.push_back (1); }
            a.push_back (b[i]);
        }

        cout << a.size() << endl;
        for (auto now : a) { cout << now << " "; } cout << endl; 
    }

    return 0;
}