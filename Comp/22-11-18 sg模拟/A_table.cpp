#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int a[70];

int main ()
{
	int n = 60;
	a[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		a[i] = a[i - 1] * 2 + 1; 
	}
	
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << endl;
	}
	// 2 ^ n - 1
	return 0;
}

