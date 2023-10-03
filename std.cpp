#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define re  
#define ll long long
#define maxn 10010
#define maxm 20020
using namespace std;
int n,m;
int to[maxm],nxt[maxm],w[maxm],cnt;
int hd[maxn];
inline void addedge(int u,int v,int we){
	++cnt;
	to[cnt]=v;
	nxt[cnt]=hd[u];
	hd[u]=cnt;
    w[cnt]=we;
}
int a,b,c;
int rt,sum;
int siz[maxn],maxpart[maxn];
bool removed[maxn];
void getrt(int u,int f){
	siz[u]=1;
	maxpart[u]=0;
	for(re int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f||removed[v])continue;
		getrt(v,u);
		siz[u]+=siz[v];
		if(siz[v]>maxpart[u])maxpart[u]=siz[v];
	}
	maxpart[u]=max(maxpart[u],sum-siz[u]);
	if(maxpart[u]<maxpart[rt])rt=u;
}
int q[110];
int dis[maxn]; 
int tmp[maxn],tot;
inline void getdis(int u,int f){
    tmp[++tot]=dis[u];
//    cout<<u<<"dis:"<<dis[u]<<'\n';
	for(re int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f||removed[v])continue;
		dis[v]=dis[u]+w[i];
		getdis(v,u);
	}
}
#define maxdis 100001000
int stac[maxn],top;
bool ans[110];
bitset<maxdis> judge;
inline void solve(int u){
    judge[0]=true;
//	cout<<"u:"<<u<<'\n';
	for(re int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(removed[v])continue;
		dis[v]=w[i];
		getdis(v,u);
		for(re int j=1;j<=tot;++j){
			for(re int k=1;k<=m;++k){
				if(tmp[j]<=q[k])ans[k]|=judge[q[k]-tmp[j]];
			}
		}
//		cout<<"v:"<<v<<'\n';
		while(tot){
			stac[++top]=tmp[tot];
			judge[tmp[tot]]=true;
//            cout<<tmp[tot]<<' ';
			--tot;
		}
//		cout<<'\n';
	}
    while(top){
    	judge[stac[top]]=false;
    	--top;
	}
}
inline void divide(int u){
	removed[u]=true;
	solve(u);
	for(re int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(removed[v])continue;
		sum=siz[v];
		maxpart[rt]=inf;
		getrt(v,u);
		getrt(rt,u);
		divide(rt);
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    cin>>n>>m;
	for(re int i=1;i<=n-1;++i){
        cin>>a>>b>>c;
		addedge(a,b,c);
		addedge(b,a,c);		
	} 
	for(re int i=1;i<=m;++i){
		cin>>q[i];
	}
	maxpart[rt]=inf;
	sum=n;
	getrt(1,0);
	getrt(rt,0);
	cout<<rt<<'\n';
	divide(rt);
	for(re int i=1;i<=m;++i){
		if(ans[i])cout<<"AYE\n";
		else cout<<"NAY\n";
	}
	return 0;
}
/*

*/