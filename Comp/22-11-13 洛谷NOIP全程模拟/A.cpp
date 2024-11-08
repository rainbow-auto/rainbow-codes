#include <iostream>
using namespace std;

long long n, k;

int ans;

int solve (int now, int m)
{
	int ansnow = 0;
	ansnow ++;
	now -= k;
	if (now <= 0)
	{
		return 0;
	}
	if (ansnow <= m / 2)
	{
		ansnow += 2 * solve (now, now);
	}
	else
	{
		ansnow += solve (now, now);
	}
	return ansnow;
}

int main ()
{
	cin >> n >> k;
	
	cout << solve (n, n) << endl;
	
	return 0;	
} 
