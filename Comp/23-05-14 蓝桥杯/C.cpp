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

int n, m;

int solve (int k)
{
	int cnt = 0;
	for (int i = 2; i * i <= k; i++)
	{
		if (k % i == 0)
		{
			while (k % i == 0)
			{
				k /= i;
				cnt ++;
			}
		}
	}
	return cnt;
}

int main ()
{
	cin >> n >> m;
	
	int ans = 0;
	for (int i = n; i <= m; i++)
	{
		ans = max (ans, solve (i));
	}
	cout << ans << endl;
	
	return 0;
}

