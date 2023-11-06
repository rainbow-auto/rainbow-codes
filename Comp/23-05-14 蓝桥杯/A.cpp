#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>

#define endl "\n"

using namespace std;

int n;

int main ()
{
	cin >> n;
	cout << n - (n / 10) << endl;
	
	return 0;
}

