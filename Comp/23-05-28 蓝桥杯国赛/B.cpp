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
map<int, int> t;

int main ()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		t[a[i]] ++;	
	}	
	
	for (int i = 1; i <= n; i++)
	{
		if (t[a[i]] > n / 2)
		{
			cout << a[i] << endl;
			return 0; 
		}	
	}
	cout << "No" << endl;
	
	return 0;
}

