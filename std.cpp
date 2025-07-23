#include<bits/stdc++.h>
using namespace std;

const int N=55,mod=1e9+7;
int n,m,f[N][N][N*N*2];
inline void add(int &x,int y){x+=y;x-=(x>=mod)*mod;}
int main()
{
	scanf("%d%d",&n,&m);
	f[0][0][N*N]=1;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=i;j++) {
            for(int k=-n*n;k<=n*n;k++) {
                add(f[i][j][k+N*N],f[i-1][j][k+N*N]);
                if(j) add(f[i][j][k+N*N],2ll*f[i-1][j][k+N*N]*j%mod);							
                if(j&&k+i*2<=n*n) add(f[i][j][k+N*N],f[i-1][j-1][k+i*2+N*N]);
                if(j<i-1&&k-i*2>=-n*n) add(f[i][j][k+N*N],1ll*(j+1)*(j+1)*f[i-1][j+1][k-i*2+N*N]%mod);
                std::cerr << f[i][j][k + N * N] << " ";
            }
            std::cerr << "\n";
        }
    }
	printf("%d",f[n][0][m+N*N]);
	return 0;
}

/*
0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 
0 0 0 0 0 1 0 3 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 1 0 2 0 3 0 0 0 0 0 
0 0 0 1 0 4 0 9 0 4 0 0 0 0 0 0 0 0 0 
0 3 0 5 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
*/