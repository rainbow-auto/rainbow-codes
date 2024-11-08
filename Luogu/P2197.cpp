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

const int maxn = 10005;

int T;

int n;
int a[maxn];

int main ()
{
	fastread
	
	cin >> T;
	
	while (T--)
	{
		cin >> n;
		
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			ans = ans xor a[i];
		}
		
		if (ans) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}