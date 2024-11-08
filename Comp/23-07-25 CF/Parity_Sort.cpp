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

int T;
int n;

int a[maxn];

int main () {
	fastread
	
    cin >> T;

    while (T--) {
        cin >> n;

        vector<int> b;
        vector<int> c;
        for (int i = 1; i <= n; i++) {
            int now; cin >> now;
            a[i] = now;
            if (now % 2 == 1) { b.push_back (now); }
            else { c.push_back (now); }
        }

        sort (b.begin(), b.end());
        sort (c.begin(), c.end());
        
        int bi = 0, ci = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] % 2 == 1) { a[i] = b[bi++]; }
            else { a[i] = c[ci++]; }
        }

        bool flag = false;
        for (int i = 2; i <= n; i++) {
            if (a[i] < a[i - 1]) { cout << "NO" << endl; flag = true; break; } 
        }

        if (not flag) { cout << "YES" << endl; }
    }

	return 0;
}
