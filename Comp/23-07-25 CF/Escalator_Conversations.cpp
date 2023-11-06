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

int T;
int n, m, k, h;

int main () {
	fastread
	
    cin >> T;

    while (T--) {
        cin >> n >> m >> k >> h; 

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int now; cin >> now;
            int delta = abs (h - now);
            if (delta % k == 0 and delta / k >= 1 and delta / k < m) { ans ++; }
        }  

        cout << ans << endl;
    }

	return 0;
}
