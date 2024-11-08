#include <iostream>
using namespace std;

long long n, k;

int ans;

void solve (int now, int m)
{
	ans ++;
	now -= k;
	if (now <= 0)
	{
		return;
	}
	if (now <= m / 2)
	{
		solve (now, now);
		solve (now, now);
	}
	else
	{
		solve (now, m);
	}
}

int main ()
{
	cin >> n >> k;
	
	solve (n, n);
	cout << ans << endl;
	
	return 0;	
} 
