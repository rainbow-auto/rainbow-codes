#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 105;

int n, m;
string s[maxn];

int main () {
	fastread

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    int ans = 0;
    int ansnow = 0;

    for (int i = 0; i < m; i++) {
        bool flag = true;
        for (int j = 1; j <= n; j++) {
            if (s[j][i] == 'x') {flag = false; break;}
        }
        
        if (flag == false) {ans = max (ans, ansnow); ansnow = 0;}
        else {ansnow ++;}
    }

    ans = max (ans, ansnow);

    cout << ans << endl;

	return 0;
}
