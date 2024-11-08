#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 500005;
char s[maxn];
int spos;

int dp_min[maxn][3];
int dp_max[maxn][3];

int solve ()
{
	int curr = spos;
	if (s[curr] == '0')
	{
		dp_max[curr][0] = 1;
		dp_max[curr][1] = 0;
		dp_max[curr][2] = 0;
		
		dp_min[curr][0] = 1;
		dp_min[curr][1] = 0;
		dp_min[curr][2] = 0;
	}
	else if (s[curr] == '1')
	{
		++spos;
		int son = solve ();
		
		dp_max[curr][0] = max (dp_max[son][1], dp_max[son][2]) + 1;
		dp_max[curr][1] = max (dp_max[son][0], dp_max[son][2]);
		dp_max[curr][2] = max (dp_max[son][0], dp_max[son][1]);
		
		dp_min[curr][0] = min (dp_min[son][1], dp_min[son][2]) + 1;
		dp_min[curr][1] = min (dp_min[son][0], dp_min[son][2]);
		dp_min[curr][2] = min (dp_min[son][0], dp_min[son][1]);
	}
	else if (s[curr] == '2')
	{
		++spos;
		int lson = solve();
		
		++spos;
		int rson = solve ();
		
		dp_max[curr][0] = max (dp_max[lson][1] + dp_max[rson][2], dp_max[lson][2] + dp_max[rson][1]) + 1;
		dp_max[curr][1] = max (dp_max[lson][0] + dp_max[rson][2], dp_max[lson][2] + dp_max[rson][0]);
		dp_max[curr][2] = max (dp_max[lson][0] + dp_max[rson][1], dp_max[lson][1] + dp_max[rson][0]);
		
		dp_min[curr][0] = min (dp_min[lson][1] + dp_min[rson][2], dp_min[lson][2] + dp_min[rson][1]) + 1;
		dp_min[curr][1] = min (dp_min[lson][0] + dp_min[rson][2], dp_min[lson][2] + dp_min[rson][0]);
		dp_min[curr][2] = min (dp_min[lson][0] + dp_min[rson][1], dp_min[lson][1] + dp_min[rson][0]);
	}
	
	return curr;
}

int main ()
{
	cin >> s;
	
	memset (dp_min, 0x3f, sizeof (dp_min));
	memset (dp_max, 0, sizeof (dp_max));
	
	spos = 0;
	solve ();
	
	int ans_max = 0;
	ans_max = max (ans_max, dp_max[0][0]);
	ans_max = max (ans_max, dp_max[0][1]);
	ans_max = max (ans_max, dp_max[0][2]);
	cout << ans_max << " ";	
		
	int ans_min = 0x3f3f3f3f;
	ans_min = min (ans_min, dp_min[0][0]);
	ans_min = min (ans_min, dp_min[0][1]);
	ans_min = min (ans_min, dp_min[0][2]);
	cout << ans_min << endl;	
	
	return 0;
}

