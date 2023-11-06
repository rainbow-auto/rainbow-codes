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

const int maxn = 55;

int T;
int n;

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
			int a, b;
			cin >> a >> b;
			if (a > b)
			{
				ans ++;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
