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

const int maxn = 1000005;

int n;
int a[maxn];

int main ()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int min_a = 0x3f3f3f3f;
			for (int k = i; k <= j; k++)
			{
				min_a = min (min_a, a[k]);
			}
				
			ans = max (ans, (j - i + 1) * min_a);			
		}	
	}	
	
	cout << ans << endl;
	
	return 0;
}

