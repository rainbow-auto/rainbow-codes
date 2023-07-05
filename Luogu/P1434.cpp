#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 205;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
int a[maxn][maxn];
int f[maxn][maxn];

int solve (int nowx, int nowy)
{
	if (f[nowx][nowy]) return f[nowx][nowy];
	f[nowx][nowy] = 1;

	for (int i = 0; i < 4; i++)
	{
		int px = nowx + dx[i];
		int py = nowy + dy[i];
		
		if (px > 0 and px <= n and py > 0 and py <= m and a[nowx][nowy] > a[px][py])
		{
			solve (px, py);
			f[nowx][nowy] = max (f[nowx][nowy], f[px][py] + 1);
		}
	}
	return f[nowx][nowy]; 
}

int main ()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}	
	}	
	
	memset (f, 0, sizeof (f));
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			ans = max (ans, solve(i, j));			
		}	
	}	
	cout << ans << endl;

	return 0;
}