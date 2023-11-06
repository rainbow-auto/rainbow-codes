#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

const int maxn = 105;

int n;
int a[maxn], s[maxn];
int ans;
int ave;

int main ()
{
	freopen ("share.in", "r", stdin);
	freopen ("share.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ave += a[i];
		s[i] = a[i] + s[i - 1];
	}
	
	ave /= n;
	for (int i = 1; i <= n - 1; i++)
	{
		if (ave * i != s[i]) 
		{
			ans ++;
		}
	}
	
	cout << ans << endl;
	return 0;
}

