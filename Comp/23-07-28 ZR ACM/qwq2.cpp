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

using namespace std;

const int maxn=3010;
const int maxp=12;

int n,k; 
int p[maxn],w[maxn][maxp];

int dp[maxn];
#define mid ((l+r)>>1)
struct tree{
	int ls,rs,val;
}t[maxn*32*32];
int root[maxn*maxn],cnt;
void modify(int &p,int lsp,int l,int r,int pos,int v){
	if(!p)p=++cnt;
	if(l==r)t[p].val=max(t[p].val,v);
	if(mid>=pos)modify(t[p].ls,l,mid,pos,v);
	else modify(t[p].rs,mid+1,r,pos,v);
}

int main () {
	fastread
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>p[i];
		for(int j=1;j<=p[i];++j){
			cin>>w[i][j];
		}
	}
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j ++) {
		   if(j+p[i]<=k)dp[i][j+p[i]] = max (dp[i][j+p[i]], dp[i][j] + w[i][p[i]]);
		   else{
		   	    dp[i][j+w[i][k-j]]=max(dp[i][j+w[i][k-j]],dp[i][j]+w[i][k-j]);
		   }
		}
	}
	*/
	for (int i = 1; i <= n-1; i++) {
		for (int j = k; j >= 0; --j) {
		   for (int x = 0; x <= j; x++) {
			   if(x+p[i]<=k){
			   	    dp[x+p[i]] = max (dp[x+p[i]], dp[j] + w[i][p[i]]);
	//		   	    cout<<i<<" "<<j<<" "<<j+w[i][p[i]]<<" "<<dp[j]<<" "<<dp[j]+w[i][p[i]]<<'\n';
			   }
			   else if(j>=k)continue;
			   else{
			   	    dp[k]=max(dp[k],dp[x]+w[i][k-x]);
			   }
		   }
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = W; j >= w[i]; j --) {
//			dp[j] = max (dp[j], dp[j - w[i]] + v[i]);
//		}
//	}
    	for(int j=0;j<=k;++j){
    		cout<<j<<" "<<dp[j]<<'\n';
		}
	cout<<dp[k]<< endl;
	return 0;
}/*
6 10
1 5
4 1 2 3 4
4 3 2 4 1
4 3 1 2 4
4 1 5 2 6
4 1 1 1 3




out: 18
*/
