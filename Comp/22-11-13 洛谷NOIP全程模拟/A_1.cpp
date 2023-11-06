#include <iostream>
using namespace std;

long long n, k;

int solve (int now, int m)
{
	int ansnow = 0;
	ansnow ++;
	now -= k;
	if (ansnow <= 0)
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
	for (int i = 1; i <= 10; i ++)
	{
		for (int j = 1; j <= 10; j++)
		{
			ans = 0;
			k = j;
			solve (i, i);
			cout << ans << " ";
		}
		cout << endl;
	}	
	return 0;	
} 
