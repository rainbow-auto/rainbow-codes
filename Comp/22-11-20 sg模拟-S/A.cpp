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
 
const int maxn = 100005;
int n;

struct Point {
	int x, y;
};
Point a, b;
Point ps[maxn];

inline int dis (Point p1, Point p2) // dis ^ 2
{
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
} 

bool operator < (Point p1, Point p2)
{
	return dis (a, p1) < dis (a, p2);
}


int main ()
{
	freopen ("missile.in", "r", stdin);
	freopen ("missile.out", "w", stdout);
	cin >> a.x >> a.y >> b.x >> b.y;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> ps[i].x >> ps[i].y;
	}
	
	sort (ps + 1, ps + n + 1);
	
	int ans = 0x3f3f3f3f;
	int mx = 0; // i ~ n 的最大值 
	for (int i = n; i >= 1; i--) // 分界点 
	{
		ans = min (ans, mx + dis(ps[i], a));	
		mx = max (mx, dis (ps[i], b));
	}
	
	cout << ans << endl;	
	
	fclose (stdin);
	fclose (stdout);
	
	return 0;
}

