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

const int maxn = 305;
int n;
int a, b;

int c[maxn];

int main ()
{
	cin >> n >> a >> b;
	
	for (int i = 1; i <= n; i++)	
	{
		cin >> c[i];		
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (c[i] == a + b)
		{
			cout << i << endl;
			break;		
		}
	}

	return 0;
}

