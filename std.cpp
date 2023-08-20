#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1010,M=5e5+10,inf=1e9;
int cur[N*2],d[N*2],f[N],a[N];
int len,s,t,n,cnt=1;
bool vis[N*2];
struct edge{int fr,to,cap;}e[M];
vector<int>g[N];
queue<int>q;
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].fr=u;
	e[cnt].cap=w;
	g[u].push_back(cnt);
	e[++cnt].to=u;
	e[cnt].fr=v;
	e[cnt].cap=0;
	g[v].push_back(cnt);
}
bool bfs(){
	for(int i=s;i<=t;i++) vis[i]=d[i]=0;
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<g[u].size();i++){
			int id=g[u][i],v=e[id].to;
			if(vis[v]||!e[id].cap) continue;
			vis[v]=1;
			d[v]=d[u]+1;
			q.push(v);
		}
	}
	return vis[t];
}
int dfs(int u,int w){
	if(u==t||!w) return w;
	int f,res=0;
	for(int &i=cur[u];i<g[u].size();i++){
		int id=g[u][i],v=e[id].to;
		if(d[v]!=d[u]+1||!(f=dfs(v,min(w,e[id].cap)))) continue;
		res+=f;
		w-=f;
		e[id].cap-=f;
		e[id^1].cap+=f;
		if(!w) break;
	}
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[i]=1;
		for(int j=1;j<i;j++)
			if(a[j]<=a[i]&&f[j]+1>f[i])
				f[i]=f[j]+1;
		len=max(len,f[i]);
	}
	printf("%d\n",len);
	if(len==1){
		printf("%d\n",n);
		sort(a+1,a+1+n);
		int t=unique(a+1,a+1+n)-a-1;
		printf("%d\n",t);
		return 0;
	}
	s=0,t=2*n+1;
	for(int i=1;i<=n;i++){
		add(i,i+n,1);
		if(f[i]==1) add(s,i,inf);
		if(f[i]==len) add(i+n,t,inf);
		for(int j=i+1;j<=n;j++)
			if(a[i]<=a[j]&&f[i]+1==f[j])
				add(i+n,j,1);
	}
	int ans=0;
	while(bfs()){
		for(int i=s;i<=t;i++) cur[i]=0;
		ans+=dfs(s,inf);
	}
	printf("%d\n",ans);
	for(int i=s;i<=t;i++) g[i].clear();
	ans=0,cnt=1;
	for(int i=1;i<=n;i++){
		if(i==1||i==n) add(i,i+n,inf);
		else add(i,i+n,1);
		if(f[i]==1){
			if(i==1||i==n) add(s,i,inf);
			else add(s,i,1);
		}
		if(f[i]==len){
			if(i==1||i==n) add(i+n,t,inf);
			else add(i+n,t,1);
		}
		for(int j=i+1;j<=n;j++)
			if(a[i]<=a[j]&&f[i]+1==f[j])
				add(i+n,j,1);
	}
	while(bfs()){
		for(int i=s;i<=t;i++) cur[i]=0;
		ans+=dfs(s,inf);
	}
	printf("%d\n",ans);
	return 0;
}
