#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main ()
{
	priority_queue <int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.top() << endl;
	return 0;
}

