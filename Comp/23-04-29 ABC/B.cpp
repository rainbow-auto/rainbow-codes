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

const int maxn = 35;

int H, W;
char a[maxn][maxn];
char b[maxn][maxn];

char old_a[maxn][maxn];
char mid_a[maxn][maxn];
bool solve (int s, int t)
{
	memcpy (old_a, a, sizeof (a));
	
	// s
	for (int j = 1; j <= W; j++)
	{
		for (int i = 1; i <= H; i++)
		{
			int nxt_i = i - s;
			if (nxt_i <= 0)
			{
				nxt_i += H;
			}
			a[nxt_i][j] = old_a[i][j];
		}
	}	
	
	memcpy (mid_a, a, sizeof (a));	
	// t
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			int nxt_j = j - t;
			if (nxt_j <= 0)
			{
				nxt_j += W;
			}
			a[i][nxt_j] = mid_a[i][j];
		}
	}	
	
	bool res = true;
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (a[i][j] != b[i][j])
			{
				res = false;
				break;
			}
		}
	}	
	
	memcpy (a, old_a, sizeof (old_a));
	return res;
} 

int main ()
{
	cin >> H >> W;

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cin >> a[i][j];
		}
	}
	
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cin >> b[i][j];
		}
	}
	
	for (int s = 1; s <= H; s++)
	{
		for (int t = 1; t <= W; t++)
		{
			if (solve (s, t))
			{
				cout << "Yes" << endl;
				return 0;
			}
		}	
	}		
	cout << "No" << endl;

	return 0;
}

