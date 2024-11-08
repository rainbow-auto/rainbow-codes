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

int main ()
{
	fastread
	
	int T; cin >> T;
	
	while (T--)
	{
		long long n; cin >> n;
		cout << (long long) (n * (1 - 6 / acos(-1) / acos(-1))) << endl;
	}
		
	return 0;
}
