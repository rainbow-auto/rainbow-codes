#include <iostream>
#include <string>
#include <map>
#include <set>
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
deque<int> q;

int main ()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	sort (a + 1, a + n + 1);
	int m = unique (a + 1, a + n + 1) - a - 1;
	
	for (int i = 1; i <= m; i++)
	{
		q.push_back(a[i]);
	}
	
	int cnt = 0;
	while (q.size() >= 3)
	{
		if (cnt % 2 == 0)
		{
			q.pop_front();
			cnt ++;
		}
		else if (cnt % 2 == 1)
		{
			q.pop_back();
			cnt ++;
		}
	}	
	
	cout << cnt << " ";
	cout << q.front() << " " ;
	cout << q.back() << " " ;
		
	return 0;
}

