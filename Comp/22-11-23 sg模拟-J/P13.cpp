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

int to_num (string s)
{
	int res = 0;
	int base = 1;
	for (int i = 0; i < s.size(); i++) base *= 10;
	for (int i = 0; i < s.size(); i++)
	{
		base /= 10;
		res += (s[i] - '0') * base;
	}
	return res;
}

int main ()
{
//	#ifdef ASDFGHJKL 
	string a;
	string r;
	cin >> a;
	r = a; reverse (r.begin (), r.end ());
	int a_num = to_num (a);	
	int r_num = to_num (r);
	
	cout << a_num + r_num << endl;
//	#endif
	
	return 0;
}

