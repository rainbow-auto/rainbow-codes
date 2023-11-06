#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <vector>

using namespace std;

const int maxn = 100005;

int n;
int k;

int a[maxn];

priority_queue <int> q;

int main ()
{
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];	
	}	
	
	for (int i = 1; i <= k; i++)
	{
		int p;
		cin >> p;
		for (int j = 1; j <= p - 1; j++)
		{
			q.push(a[j]);	
		}	
		int ans = 0;
		
		int cnt = 0;
		for (int j = p; j <= n; j++)
		{
			q.push(a[j]);
			if (cnt % 2 == 0)
			{
				ans += q.top();
			}
			q.pop();
			cnt ++;
		}
		while (not q.empty ())
		{
			if (cnt % 2 == 0)
			{
				ans += q.top();
			}
			q.pop();
			cnt ++;
		}
		cout << ans << endl;
	}
	
	return 0;
}

