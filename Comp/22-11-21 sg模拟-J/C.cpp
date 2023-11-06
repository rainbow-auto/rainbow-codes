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
priority_queue <int, vector <int>, greater<int> > q;

int main ()
{
	freopen ("merge.in", "r", stdin);
	freopen ("merge.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int now;
		cin >> now;		
		q.push(now);
	}
	
	int ans = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		int x = q.top (); q.pop ();
		int y = q.top (); q.pop ();
		ans += x + y;
		q.push(x + y);
	}
	
	cout << ans << endl;
	fclose (stdin);
	fclose (stdout); 
	return 0;
}

