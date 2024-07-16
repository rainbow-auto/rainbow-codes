#include<iostream>
#include<cmath>
using namespace std;
int n,m;
long long f[1005][1005];
long long ans;
long long qmi(long long b,long long p)
{
	long long res=1;
	while(p)
	{
		if(p&1)
		{
			res=res*b%1000000007;	
		}
		b=b*b%1000000007;
		p>>=1;
	}
	return res;
}
int main()
{
	// freopen("seg.in","r",stdin);
	// freopen("seg.out","w",stdout);
	cin>>n>>m;
	f[0][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int k=i+1;k<=n;k++)
		{
			for(int j=0;j<=m;j++)
			{
				f[k][j+1]=(f[k][j+1]+(f[i][j]*(qmi(2,k-i)-1)%1000000007)*qmi(2,(n-k)*(k-i))%1000000007)%1000000007;
			}
		}
	}

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            std::cerr <<f[i][j] << " ";
        }
        std::cerr << "\n";
    }

	for(int i=1;i<=n;i++)
	{
		ans=(ans+f[i][m])%1000000007;
	}
	cout<<ans<<endl;
	return 0;
 }