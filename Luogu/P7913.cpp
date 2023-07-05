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

const int maxn = 200005; 

struct Plane{
	int start, end;
	friend bool operator < (Plane a, Plane b)
	{
		if (a.start == b.start) return a.end < b.end;
		else return a.start < b.start;		
	}
};

struct Node{
	int id;
	int end;
	friend bool operator < (Node a, Node b)
	{
		if (a.end == b.end) return a.id > b.id;
		else return a.end > b.end;
	}
};
int n, m1, m2;
Plane p1[maxn];
Plane p2[maxn];

int res1[maxn];
int res2[maxn];

void solve (Plane p[], int m, int res[])
{
	priority_queue <int, vector<int>, greater<int> > fq;
	priority_queue <Node> lq;
	 
	for (int i = 1; i <= m; i++)
	{
		fq.push(i);
	}
	for (int i = 1; i <= m; i++)
	{
		while (not lq.empty() and p[i].start >= lq.top().end)
		{
			fq.push(lq.top().id);
			lq.pop ();
		}
		
		if (fq.empty()) continue;
		
		int id = fq.top();
		fq.pop();
		lq.push(Node{id, p[i].end});
		res[id] ++;
	}
	
	for (int i = 1; i <= n; i++)
	{
		res[i] += res[i - 1];
	}
}

int main ()
{
//	freopen ("airport.in", "r", stdin);
//	freopen ("airport.out", "w", stdout);
	
	cin >> n >> m1 >> m2;
	for (int i = 1; i <= m1; i++)
	{
		cin >> p1[i].start >> p1[i].end;	
	}
	for (int i = 1; i <= m2; i++)
	{
		cin >> p2[i].start >> p2[i].end;
	}
	sort (p1 + 1, p1 + m1 + 1);
	sort (p2 + 1, p2 + m2 + 1);
	
	solve (p1, m1, res1);
	solve (p2, m2, res2);
	
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		ans = max (ans, res1[i] + res2[n - i]);
	}
	cout << ans << endl;
	
	return 0;
}