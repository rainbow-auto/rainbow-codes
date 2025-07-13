#include<bits/stdc++.h>
using std::min;
const int N = 35, m = 30;
long long a[N], dp[N][2];//处理完 0~i 位且下一位不进位/进位 最小代价
int main() {
    int T; scanf("%d", &T); while(T--) {
        int x, k; scanf("%d%d", &x, &k);
        x = abs(x - k);
		std::cerr << x << "\n";
        scanf("%d", &k);
        for(int i = 0; i <= k; i++) {
            scanf(/*"%d"*/"%lld", a + i);
            if(i) a[i] = min(a[i], a[i - 1] << 1);
        }
        for(int i = k + 1; i <= m; i++) a[i] = a[i - 1] << 1;
        memset(dp, 0x3f, sizeof dp);
        if(x & 1) dp[0][0] = dp[0][1] = a[0];
        else dp[0][0] = 0;

		std::cerr << dp[0][0] << " " << dp[0][1] << "\n";

        for(int i = 1; i <= m; i++) {
            if((x >> i) & 1)
                dp[i][0] = dp[i - 1][0] + a[i],
                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + a[i]);
            else
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + a[i]),
                dp[i][1] = dp[i - 1][1] + a[i];
			std::cerr << dp[i][0] << " " << dp[i][1] << "\n";
		}
        printf("%lld\n", dp[m][0]);
    }
}

/*
6
0 4557430888798830399
2 2
5 2
5 8
5 20
5 44
5 92
5 188
5 380
5 764
5 1532
5 3068
5 6140
5 12284
5 24572
5 49148
5 98300
5 196604
5 393212
5 786428
5 1572860
5 3145724
5 6291452
5 12582908
5 25165820
5 50331644
5 100663292
5 201326588
5 402653180
5 805306364
5 1610612732
*/