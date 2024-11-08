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

int main () {
	fastread

	for (int i = 1; i <= 8; i++) {
		int now; cin >> now;
		if (now == 9) { cout << "F" << endl; return 0; }
	}	

	cout << "S" << endl;

	return 0;
}
