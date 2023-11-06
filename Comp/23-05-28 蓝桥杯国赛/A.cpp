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

int n;
string s, rs;

bool check (int i)
{
	s = "";
	while (i)
	{
		int now = i % 8;
		i /= 8;
		s += now + '0';
	}
	
	rs = s;
	reverse (rs.begin(), rs.end());
	if (s == rs)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int main ()
{
	cin >> n;
	
	for (int i = 1; i * i <= n; i++)
	{
		if (check(i * i))
		{
			cout << i * i << " ";
		}
	}
	
	return 0;
}

