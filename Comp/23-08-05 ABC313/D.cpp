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
//#define endl "\n"

using namespace std;

const int maxn = 1005;

int n, k;

int main () {
	fastread
	
	cin >> n >> k;

	int pre_k;
	cout << "? ";
	for (int i = 1; i <= k; i++) {
		cout << i << " "; 
	}
	cin >> pre_k;
	
	for (int i = 1; i <= n; i++) {
		cout << "? ";
		for (int j = 1; j <= k - 1; j++) { cout << i << " "; }
		cout << i << endl;
		
		
	}
	
	return 0;
}
