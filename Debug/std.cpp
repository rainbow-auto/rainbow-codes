//#include<__msvc_all_public_headers.hpp>
#include<bits/stdc++.h>
using namespace std;
int dp[3005][3005][15];
int w[15];
int main()
{
    // cin.tie(0);
	// ios::sync_with_stdio(false);
	int n, k;
	memset(dp, -0x3f, sizeof dp);//将所有数据设成无效值
	dp[0][0][0] = 0;//初始化取0个物品0重量，没有取部分的物品时的值为0
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int p;
		cin >> p;
		for (int j = 1; j <= p; j++)
		{
			cin >> w[j];//每个物品取不同重量的价值
		}
		for (int j = k - 1; j >= 0; j--)
		{//取第i个物品前当前取的重量
			dp[i][j][1] = dp[i - 1][j][1];
			dp[i][j][0] = dp[i - 1][j][0];//先从上一个物品转移过来用来做之后的比较
			if (j + p <= k)
			{//当前背包能完整的装下当前物品
				dp[i][j + p][0] = max(dp[i][j + p][0], dp[i - 1][j][0] + w[p]);
				dp[i][j + p][1] = max(dp[i][j + p][1], dp[i - 1][j][1] + w[p]);//从i-1,j转移
			}
			for (int jj = 1; jj < p && j + jj <= k; jj++)
			{//当前物品取jj份重量
				dp[i][j + jj][1] = max(dp[i][j + jj][1], dp[i - 1][j][0] + w[jj]);//从i-1,j,0,转移
			}			
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{//枚举i，j找到最大值
			ans = max(ans, dp[i][j][0]);
		}
		ans = max(ans, dp[i][k][1]);//对于每个物品，如果要取部分重量，那此时重量肯定的等于背包总重
	}
	cout << ans << endl;

	return 0;
}
