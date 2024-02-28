#include<bits/stdc++.h> 
using namespace std;
int n,m,ans=0;
int a[105][105];
bool used[105][105];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void dfs(int x,int y)
{
	std::cerr << x << " " << y << "\n";
	
	used[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(a[nx][ny]==0 || used[nx][ny]==1) continue;
		dfs(nx,ny);
	}
}
int main()
{
	cin>>n>>m;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) 
			scanf("%1d",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(used[i][j]==0 && a[i][j]!=0)
			{
				dfs(i,j);
				ans++;
				std::cerr << "\n";
			}
		}
	}
	cout<<ans;	
	return 0;
}