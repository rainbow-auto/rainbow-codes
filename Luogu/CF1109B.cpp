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

string s;

int main () {
	fastread
	
	cin >> s; int n = s.size();
	
	int cnt = 0;
	for (int i = 0; i < (n >> 1); i++) {
		cnt += s[i] != s[0]; 
	}

	if (not cnt) { cout << "Impossible" << endl; return 0; }
	
	for (int i = 1; i <= (n >> 1); i++) {
		string T = s.substr(i, n) + s.substr(0, i);
		string S = T; reverse(S.begin(), S.end());
		if (S == T and T != s) {
			cout << 1 << endl;
			return 0;
		}
	}
	
	cout << 2 << endl;
	
	return 0;
}
