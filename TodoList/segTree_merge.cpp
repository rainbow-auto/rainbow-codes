#include<bits/stdc++.h>
#define re register
#define pii pair<int,int>
#define mk make_pair
#define mid ((l+r)>>1)
#define maxn 100010
#define maxm 200020
using namespace std;
int n,m;
int to[maxm],nxt[maxm],cnt;
int head[maxn];
inline void addedge(int u,int v){
	cnt++;
	to[cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
} 
int a,b;
int fa[maxn],dep[maxn],siz[maxn],son[maxn];
void dfs1(int u,int f){
	fa[u]=f;
	dep[u]=dep[f]+1;
	siz[u]=1;
	for(re int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f)continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
int top[maxn];
void dfs2(int u,int t){
	top[u]=t;
	if(son[u])dfs2(son[u],t);
	for(re int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
inline int lca(int u1,int u2){
	while(top[u1]!=top[u2]){
		if(dep[top[u1]]<dep[top[u2]])swap(u1,u2);
		u1=fa[top[u1]];
	}
	return dep[u1]<dep[u2]?u1:u2; 
}
int c;
int tot;
struct tree{
	int l,r;
	pii val;
}t[maxn*70];
int root[maxn];
pii max(pii x,pii y){
	if(x.first!=y.first)return x.first>y.first?x:y;
	else return x.second<y.second?x:y;
}
inline void pushup(int p){
	t[p].val=max(t[t[p].l].val,t[t[p].r].val);
}
void modify(int &p,int l,int r,int pos,int v){
	if(!p)p=++tot;
	if(l==r){
		t[p].val.first+=v;
		t[p].val.second=pos;
		return ;
	}
	if(mid>=pos)modify(t[p].l,l,mid,pos,v);
	else modify(t[p].r,mid+1,r,pos,v);
	pushup(p);
}
void merge(int &x,int y,int l,int r){
	if(!x||!y)x|=y;
	else if(l==r){
		t[x].val.first+=t[y].val.first;
		return ;
	}
	else{
		merge(t[x].l,t[y].l,l,mid);
		merge(t[x].r,t[y].r,mid+1,r);
		pushup(x);
	}
}
int ans[maxn];
void dfs(int u){
	for(re int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u])continue;
		dfs(v);
		merge(root[u],root[v],1,maxn);
	}
	ans[u]=t[root[u]].val.second;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
	for(re int i=1;i<=n-1;++i){
		cin>>a>>b;
		addedge(a,b);
		addedge(b,a);
	} 
	dfs1(1,0);
	dfs2(1,1);
	while(m--){
		cin>>a>>b>>c;
		modify(root[a],1,maxn,c,1);
		modify(root[b],1,maxn,c,1);
		modify(root[lca(a,b)],1,maxn,c,-1);
		modify(root[fa[lca(a,b)]],1,maxn,c,-1);
	}
	dfs(1);
	for(re int i=1;i<=n;++i)cout<<ans[i]<<'\n';
	return 0;
}