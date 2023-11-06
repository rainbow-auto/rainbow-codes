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

using namespace std;

int a, b;

int main ()
{
	fastread
	
	cin >> a >> b;
	int n = a * b;
	int ans = (n / 2 - 1) * n + n / 2;
	
	cout << ans << endl;
		
	return 0;
}
