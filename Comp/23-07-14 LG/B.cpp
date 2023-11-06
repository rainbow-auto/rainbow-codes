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

#define int long long

int n, k;

int a[maxn];
int sum[maxn];

signed main ()
{
	cin >> n >> k;
	
	for (int i = 1; i <= (n << 1); i++)
	{
		cin >> a[i];
		sum[i % k] += a[i];
	}
		
	for (int i = 1; i <= (n << 1); i++)
	{
		if (i % 2 == 1)
		{
			a[i] = sum[i % k] % i;
		}
	}
	
	for (int i = 1; i <= (n << 1); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	
	return 0;
}

