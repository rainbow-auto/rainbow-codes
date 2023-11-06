#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

const int maxn = 505;

int main ()
{
	srand(time(0) * time(0));
	cout << rand() % int(1e3 + 7) << endl;	
	return 0;
}

