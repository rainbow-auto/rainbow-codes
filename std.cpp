#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int m,d,len,a[2005];
ll f[2005][2005];
char l[2005],r[2005];
ll dfs(int k,int x,int p)
{
    if(k>len)
        return x?0:1;//当前数要整除m 
    if(!p&&f[k][x]!=-1)
        return f[k][x];
    int y=p?a[k]:9;//当前位可取的最大值 
    ll res=0;
    if(k&1)
    {
        for(int i=0;i<=y;i++)
        {
            if(i==d)
                continue;
            res=(res+dfs(k+1,(x*10+i)%m,p&&(i==y)))%mod; 
        }
    }//奇数位 
    else
    {
        if(d<=y)
            res=(res+dfs(k+1,(x*10+d)%m,p&&(d==y)))%mod;
    }//偶数位 
    if(!p)
        f[k][x]=res;//如果没有限制就记忆化 
    return res;
}
ll divide(char *s)
{
    len=strlen(s+1);
    for(int i=1;i<=len;i++)
        a[i]=s[i]-'0';
    return dfs(1,0,1);
}
bool check(char *s)
{
    len=strlen(s+1);
    int x=0;
    for(int i=1;i<=len;i++)
    {
        int y=s[i]-'0';
        x=(x*10+y)%m;
        if(i&1)
        {
            if(y==d)
                return false;
        }
        else
        {
            if(y!=d)
                return false;
        }
    }
    return !x;
}//单独判断l 
int main()
{
	memset(f,-1,sizeof(f));//初始化一遍即可，memset效率很低
    scanf("%d%d%s%s",&m,&d,l+1,r+1);
    printf("%lld\n",(divide(r)-divide(l)+check(l)+mod)%mod);
    return 0;
}
