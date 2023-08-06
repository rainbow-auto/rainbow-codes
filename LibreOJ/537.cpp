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

#include <unordered_map>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

unordered_map <string, int> t;

int k;
string s;

int main () {
	fastread

	cin >> s;
	cin >> k;
	
	int ans = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		string tmp = s.substr(i, k);
		t[tmp] ++;
		ans = max(ans, t[tmp]);
	}
	
	cout << ans << endl;
	
	return 0;
}
