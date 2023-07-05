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

const int maxn = 205;
bool dp[maxn][maxn][5];

int W, I, N, G;

string s;
int n;
bool can[5][5][5];

inline int to_num (char c)
{
	if (c == 'W') return 1;
	if (c == 'I') return 2;
	if (c == 'N') return 3;
	if (c == 'G') return 4;
}

namespace Reader{
	void read_c (int siz, int now)
	{
		for (int i = 1; i <= siz; i ++)
		{
			char c1, c2;
			cin >> c1 >> c2;
			can[now][to_num(c1)][to_num(c2)] = 1;
		} 
	}
	
	void read ()
	{
		cin >> W >> I >> N >> G;
		read_c (W, 1);
		read_c (I, 2);
		read_c (N, 3);
		read_c (G, 4);
		cin >> s;
		n = s.length();
	}
}

namespace Worker{
	inline void init ()
	{
		memset(dp, 0, sizeof (dp));
		for (int i = 1; i <= n; i++)
		{
			dp[i][i][to_num(s[i - 1])] = true;
		}
	}
	
	void solve ()
	{
		init();
		for (int len = 2; len <= n; len ++)
		{
			for (int l = 1; l + len - 1 <= n; l++)
			{
				int r = l + len - 1;
				for (int k = l; k < r; k ++)
				{
					for (int z = 1; z <= 4; z++)
					{
						for (int z1 = 1; z1 <= 4; z1++)
						{
							for (int z2 = 1; z2 <= 4; z2++)
							{
								if (can[z][z1][z2] and dp[l][k][z1] and dp[k + 1][r][z2])
								{
									dp[l][r][z] = true;
								}
							}
						}
					}
				}				
			}			
		}
		
		bool correct = false;
		if (dp[1][n][1]) {correct = true; cout << "W";}
		if (dp[1][n][2]) {correct = true; cout << "I";}
		if (dp[1][n][3]) {correct = true; cout << "N";}
		if (dp[1][n][4]) {correct = true; cout << "G";}
		if (not correct) {cout << "The name is wrong!" << endl;}
	}
}

int main ()
{
	Reader::read ();
	Worker::solve ();
	return 0;
}
