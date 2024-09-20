      
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{int v,nxt;}e[2000005]; 
int T,n,m,A,B,h[500005],w[500005],t[500005],cnt,dis[500005],vis[500005],u,v;
void add(int u,int v){e[++cnt]={v,h[u]};h[u]=cnt;}
signed main()
{
	// freopen("monster.in","r",stdin);
	// freopen("monster.out","w",stdout); 
	cin.tie(0)->sync_with_stdio(0);
	cin>>T;
	for(int _=1;_<=T;_++)
	{
		cin>>n>>m>>A>>B;
		for(int i=1;i<=n;i++)h[i]=0;cnt=0;
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v;
			add(u,v);add(v,u);
		}
		for(int i=1;i<=n;i++)cin>>w[i];
		for(int i=2;i<=n;i++)w[i]+=B;
		if(A<=B)
		{
			for(int i=2;i<=n;i++)
			{
				if(A==B)t[i]=(w[i]<w[1]?0x3f3f3f3f:0);
				else t[i]=(w[1]>w[i]?(w[1]-w[i]-1)/(B-A)+1:0);
			}
			queue<int>q;q.push(1);
			for(int i=1;i<=n;i++)dis[i]=-1;dis[1]=0;
			while(!q.empty())
			{
				int u=q.front();q.pop();
				for(int i=h[u];i;i=e[i].nxt)
				{
					int v=e[i].v;
					if(dis[v]==-1&&dis[u]+1<=t[v])
					{
						dis[v]=dis[u]+1;
						q.push(v);
					}
				}
			}
			cout<<dis[n]<<'\n';
		}
		else 
		{
			for(int i=2;i<=n;i++)t[i]=(w[i]<w[1]?1:(w[i]-w[1])/(A-B)+2);
 
            for (int i = 1; i <= n; i++) {
                std::cerr << t[i] << " ";
            }

            priority_queue<pair<int,int> >q;q.push(make_pair(0,1));
			for(int i=1;i<=n;i++)dis[i]=0x3f3f3f3f,vis[i]=0;dis[1]=0;
			int tot=0;
			while(!q.empty())
			{
				int u=q.top().second;q.pop();
				if(vis[u])continue;vis[u]=1;
				if(tot<dis[u]){dis[u]=0x3f3f3f3f;continue;}
				tot++;
				for(int i=h[u];i;i=e[i].nxt)
				{
					int v=e[i].v;
					if(dis[v]>max(dis[u]+1,t[v]))
					{
						dis[v]=max(dis[u]+1,t[v]);
						q.push(make_pair(-dis[v],v));
					}
				}
			}
			if(dis[n]==0x3f3f3f3f)cout<<-1<<'\n';
			else cout<<dis[n]<<'\n';
		}
	}
	return 0;
}
