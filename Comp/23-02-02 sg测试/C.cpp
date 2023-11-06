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

char a[10005];
char b[1000005];
int n, m;

int cnt_a[58];
int cnt[58];

int main ()
{
	fastread
	
	cin >> a + 1;
	cin >> b + 1;
	n = strlen (a + 1);
	m = strlen (b + 1);
	
	for (int i = 1; i <= n; i++) cnt_a[a[i] - 'A'] ++;
	
	for (int i = 1; i <= n - 1; i++) cnt[b[i] - 'A'] ++;
	
	int res = 0;
	for (int i = n; i <= m; i++)
	{
		cnt[b[i] - 'A'] ++;
		bool flag = true;
		for (int j = 0; j < 58; j++)
		{
			if (cnt[j] != cnt_a[j]) 
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			res ++;
		}
		cnt[b[i - n + 1] - 'A'] --;
	}
	cout << res << endl;
	
	return 0;
}
