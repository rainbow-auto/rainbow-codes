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

const int maxn = 40000005;
int z[maxn];

inline void get_z(string s) {
	for (int i = 1, l = 0, r = 0; i < (int)s.size(); i++) {
		if (i <= r and z[i - l] < r - i + 1) {
			z[i] = z[i - l];
		} else {
			z[i] = max(0, r - i + 1);
			while (i + z[i] < (int)s.size() and s[z[i]] == s[i + z[i]]) { z[i] ++; }
		}
		
		if (i + z[i] - 1 > r) { l = i; r = i + z[i] - 1; } // 更新一下r
	}
}

int main () {
	fastread
	
	string a, b;
	cin >> a >> b;
	
	get_z(b + "#" + a);
	
	long long ansz = 0, ansp = 0;
	z[0] = b.size(); 
	for (int i = 0; i < (int)b.size(); i++) {
		ansz ^= 1ll * (z[i] + 1) * (i + 1); 
	}

	for (int i = 0; i < (int)a.size(); i++) {
		ansp ^= 1ll * (z[i + b.size() + 1] + 1) * (i + 1);	
	}
	
	cout << ansz << endl;
	cout << ansp << endl;
	
//	for (int i = 0; i < (int)b.size(); i++) { cout << z[i] << " "; } cout << endl;
	
	return 0;
}
