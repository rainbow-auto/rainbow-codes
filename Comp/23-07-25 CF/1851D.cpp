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

const int maxn = 200005;

#define int long long

int T;

int n;
map<int, int> t;

signed main () {
//	fastread

    cin >> T;
    
    while (T--) {
        t.clear();

		cin >> n; 

        int x = 0;
        vector<int> y;
		
		int mx = 0;
	
        int last = 0;
        for (int i = 1; i <= n - 1; i++) {
            int now; cin >> now;
            t[now - last] ++;            
            mx = max (mx, now - last);
            last = now;
        }

        for (int i = 1; i <= n; i++) {
            if (not t[i]) { y.push_back (i); }
            if (t[i] >= 2) { x = i; }
        }

        if (mx > n) { x = mx; }        

        // cout << "siz = " << y.size() << endl;

        if (y.size() == 1) { cout << "YES" << endl; }
        else if (y.size() >= 3) { cout << "NO" << endl; }
        else if (x == y[0] + y[1]) { cout << "YES" << endl; }
        else { cout << "NO" << endl; }
    }

	return 0;
}

