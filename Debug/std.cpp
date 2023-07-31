// luogu-judger-enable-o2
#include<bits/stdc++.h>
#define N 60010
using namespace std;
inline void read(int &x)
{
    x=0;
    static int p;p=1;
    static char c;c=getchar();
    while(!isdigit(c)){if(c=='-')p=-1;c=getchar();}
    while(isdigit(c)) {x=(x<<1)+(x<<3)+(c-48);c=getchar();}
    x*=p;	
}
bool vis[N];
int prim[N],mu[N],sum[N],cnt,k;
void get_mu(int n)
{
    mu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]){mu[i]=-1;prim[++cnt]=i;}
        for(int j=1;j<=cnt&&i*prim[j]<=n;j++)
        {
            vis[i*prim[j]]=1;
            if(i%prim[j]==0)break;
            else mu[i*prim[j]]=-mu[i];
        }
    }
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+mu[i];
}
long long calc(int a,int b)
{
    static int max_rep;
    static long long ans;
    max_rep=min(a,b);ans=0;
    for(int l=1,r;l<=max_rep;l=r+1)
    {
        r=min(a/(a/l),b/(b/l));
        ans+=(1ll*a/(1ll*l*k))*(1ll*b/(1ll*l*k))*(sum[r]-sum[l-1]);
    }
    return ans;
}
int main()
{
//	freopen("P3455.in","r",stdin);
//	freopen("P3455.out","w",stdout);
	int t;
    read(t);
    get_mu(50000);
    
	for (int i = 1; i <= n; i++) {
		
	}
	
	while(t--)
    {
        static int a,b,c,d;
        read(a);read(b);read(c);read(d);read(k);
        printf("%lld\n",calc(b,d)-calc(b,c-1)-calc(a-1,d)+calc(a-1,c-1));
    }
    return 0;
}
