#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

#define int __int128

using namespace std;

inline void read(__int128 &x){
	x=0;
	__int128 f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
	    x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}
void write(__int128 x){
	if(x<0){
		putchar('-');
		x=-x;
	} 
	if(x<10)putchar(x%10+'0');
	else{
		write(x/10);
		putchar(x%10+'0');
	}
}

const int maxn = 70;

__int128 a;
int stac[maxn];
int tot;
int dp[maxn][maxn][maxn];

int mod;

int dfs(int now,int cnt, int rem,bool lead,bool limit){
	if(now>tot){
		if (rem == 0 && cnt == mod) {
//			cout<<"OK "<<qwq<<'\n';
			return 1;
		} else {
//			cout<<"BOK "<<qwq<<'\n';
			return 0;
		}
	}
	
	if (not limit and not lead and dp[now][cnt][rem] != -1) { 
		return dp[now][cnt][rem];
	}
	
	int mx = limit ? stac[tot - now + 1] : 1;
	
	int res = 0;
	for (int i = 0; i <= mx; ++i) {
		res += dfs (now + 1, cnt + i, (rem * 2 + i) % mod, lead && i == 0, limit && i == mx);
	}	
	
	if (not limit and not lead) {
		dp[now][cnt][rem] = res;
	}
	
	return res;
}

int solve(){
	while (a) {
		tot++;
		if (a & 1) { 
            stac[tot]=1;	
		}
		else stac[tot]=0;
		a >>= 1;
	}
	memset(dp,-1,sizeof(dp));
	return dfs(1, 0, 0,true,true);
}

signed main () {
//	fastread
	
	read (a);
	
	int ans = 0;
	for (int i = 1; i <= 64; i++) {
		mod = i;
		ans += solve();
//		cout << "i = " << i << " ans = " << ans << endl;
	}
	
	write(ans);
	
	return 0;
}
