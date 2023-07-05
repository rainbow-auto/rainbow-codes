#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

typedef multiset<int>::iterator sit; 
multiset<int> s;
int q;

int main ()
{
	cin >> q;
	s.insert(-2147483647);
	s.insert( 2147483647);  
	while (q--)
	{
		int op, x;
		cin >> op >> x;
		if (op == 1)
		{
			sit pos = s.lower_bound(x); 
			int res = 0;
			for (sit it = s.begin(); it != pos; it ++, res ++);
			cout << res << endl;
		}
		if (op == 2)
		{
			int pos = -1;
			for (sit it = s.begin(); it != s.end(); it++)
			{
				pos ++;
				if (pos == x)
				{
					cout << *it << endl;					
				}
			}
		}
		if (op == 3)
		{
			sit it = s.lower_bound (x); it --;
			cout << *it << endl;
		}
		if (op == 4)
		{
			sit it = s.upper_bound (x);
			cout << *it << endl; 
		}
		if (op == 5)
		{
			s.insert (x);
		} 
	}	
	return 0;
}
