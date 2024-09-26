// 这个代码长度限制在 1kb 以内真的是唐完了
// Stupid question with a stupid source code limit.

#include<bits/stdc++.h>
using i64=long long;
#define rep(QWQ,qwq,qaq)for(i64 QWQ=(qwq);(QWQ)<=(qaq);QWQ++)
const int MOD=2520;int a[23],len;i64 lcm(i64 a,i64 b){if(not a or not b)return a|b;return a/std::__gcd(a,b)*b;}int d[MOD+5];i64 f[23][MOD+5][55];i64 dfs(int now,bool lim,int cur,int rst){if(now<=0)return rst%cur==0?1:0;i64 res=0;if(not lim and~f[now][rst][d[cur]])return f[now][rst][d[cur]];rep(i,0,(lim?a[now]:9)){res+=dfs(now-1,lim and(i==a[now]),lcm(cur,i),(rst*10+i)%MOD);}if(not lim)f[now][rst][d[cur]]=res;return res;}i64 calc(i64 x){len=0;while(x){a[++len]=x%10;x/=10;}return dfs(len,true,1,0);}bool MemED;int main(){int _;std::cin>>_;int tot=0;rep(i,1,MOD)if(MOD%i==0)d[i]=++tot;memset(f,-1,sizeof(f));while(_--){i64 l,r;std::cin>>l>>r;std::cout<<calc(r)-calc(l-1)<<"\n";}return 0;}