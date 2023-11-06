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
int p[maxn];

int dp[maxn];

struct node{
	int arr[maxp];
}w[maxn];
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
			cin>>w[i].arr[j];
	    }
	}
	for (int i = 1; i <= n-1; i++) {
		for (int j = k; j >= p[i]; --j) {
			modify(root[i],root[i-1],1,maxn,j,dp[j-p[i]] + w[i].arr[p[i]]);
//		   	dp[j] = max (dp[j], dp[j-p[i]] + w[i].arr[p[i]]);
//		   	cout<<i<<" "<<j<<" "<<j-p[i]<<" "<<dp[j]<<'\n'; 
		}
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
