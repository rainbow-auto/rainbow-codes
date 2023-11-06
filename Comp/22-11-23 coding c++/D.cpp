#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

const int maxn = 1005;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m; 

int a[maxn][maxn];
bool vis[maxn][maxn];

struct Point {
	int x, y;
};

struct Node{
	int min_x, max_x;
	int min_y, max_y;
	int cnt;
	Node ()
	{
		min_x = 0x3f3f3f3f;
		min_y = 0x3f3f3f3f;
		max_x = 0;
		max_y = 0;
		cnt = 0;
	}
	inline int x_len ()
	{
		return max_x - min_x + 1;
	}
	inline int y_len ()
	{
		return max_y - min_y + 1;
	}
};

Node ns[maxn * maxn];
int curr;

bool dfs (Point now)
{
	if (now.x < 1 or now.x > n) return false;
	if (now.y < 1 or now.y > m) return false;
	if (not a[now.x][now.y]) return false;
	if (vis[now.x][now.y]) return false;
	
	vis[now.x][now.y] = true;
	
	ns[curr].min_x = min (ns[curr].min_x, now.x);
	ns[curr].max_x = max (ns[curr].max_x, now.x);			
	ns[curr].min_y = min (ns[curr].min_y, now.y);
	ns[curr].max_y = max (ns[curr].max_y, now.y);			
	ns[curr].cnt ++;
	for (int i = 0; i < 4; i++)
	{
		Point t = Point {now.x + dx[i], now.y + dy[i]};
		dfs (t);
	}
	return true; 
}

int main ()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char ch;
			cin >> ch;
			if (ch == '#')
			{
//				s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + 1;	
				a[i][j] = 1; 
			}
			else
			{
//				s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + 1;	
				a[i][j] = 0;
			}		
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (vis[i][j]) continue;
			if (a[i][j] == 0) continue;
			curr ++;
			dfs (Point{i, j});
			if (ns[curr].x_len () * ns[curr].y_len() != ns[curr].cnt)
			{
//				cout << i << ", " << j << endl;
//				cout << "xlen = " << ns[curr].x_len() << endl; 
//				cout << "ylen = " << ns[curr].y_len() << endl; 
				cout << "Bad placement." << endl;
				return 0;
			}
		}
	}
	
	printf ("There are %d ships.", curr);
	
	return 0;
}

