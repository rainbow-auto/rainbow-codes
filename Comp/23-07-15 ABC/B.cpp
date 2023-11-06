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

const int maxn = 105;

int n, m;
int func[maxn][maxn];
int p[maxn];
int c[maxn];

int main ()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i] >> c[i];
		for (int j = 1; j <= c[i]; j++)
		{
			int now; cin >> now;
			func[i][now] = 1;
		}	
	} 
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			bool flag = true;
			
			flag = flag and (p[i] >= p[j]);
		
			int more = 0;			
			for (int k = 1; k <= m; k++)
			{
				if (func[j][k] == 0 and func[i][k] == 1)
				{
					flag = false;
				}
				if (func[j][k] == 1 and func[i][k] == 0)
				{
					more ++;	
				} 
			}
						
			flag = flag and (more or p[i] > p[j]);			
						
			if (flag == true)
			{
				cout << "Yes" << endl;
				return 0;	
			}			
		}
	}
	
	cout << "No" << endl;

	return 0;
}

