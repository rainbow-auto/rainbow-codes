#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=20;
const int mod=2520;
int T,cur,a[mod+1];
ll l,r,f[20][mod+1][50];
vector<int>dim;
int gcd(int x,int y){return x%y?gcd(y,x%y):y;}
int lcm_(int x,int y){if(!y)return x;return x/gcd(x,y)*y;}
ll dfs(int x,int mode,int lcm,bool op)
{
    if(!x)return mode%lcm==0?1:0;
    if(!op&&f[x][mode][a[lcm]])return f[x][mode][a[lcm]];
    int maxx=op?dim[x]:9;ll ret=0;
    for(int i=0;i<=maxx;i++)ret+=dfs(x-1,(mode*10+i)%mod,lcm_(lcm,i),op&(i==maxx));
    if(!op)f[x][mode][a[lcm]]=ret;
    return ret;
}
ll solve(ll x)
{
    dim.clear();
    dim.push_back(-1);
    ll t=x;
    while(t)dim.push_back(t%10),t/=10;
    return dfs(dim.size()-1,0,1,1);
}

main()
{
    for(int i=1;i<=mod;i++)if(mod%i==0)a[i]=++cur;
    scanf("%d",&T);

    while(T--)scanf("%lld%lld",&l,&r),printf("%lld\n",solve(r)-solve(l-1));
    return 0;
}