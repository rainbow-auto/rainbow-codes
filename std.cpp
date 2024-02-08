#include<bits/stdc++.h>
#define N 100005
#define M N*33 
#define mid ((l+r)>>1)
#define inf 100100005
using namespace std;

inline void rd(int &X){
    X=0;int w=0;char ch=0;
    while(!isdigit(ch))w|=ch=='-',ch=getchar();
    while( isdigit(ch))X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    X=w?-X:X;
}

int L,R;
map<int,int> id,id2;
int n,m,rt,cnt,ans;
int sum[M],ls[M],rs[M];

void ins(int &p,int x,int l=-inf,int r=inf){
	if(!p) p=++cnt;sum[p]++;if(l==r) return ;
	x<=mid ? ins(ls[p],x,l,mid) : ins(rs[p],x,mid+1,r);
}
int ask(int p,int x,int l=-inf,int r=inf){
	if(!sum[p] or l==r) return 0;
	return x<=mid ? ask(ls[p],x,l,mid) : ask(rs[p],x,mid+1,r)+sum[ls[p]];
}
int find(int p,int k,int l=-inf,int r=inf){
	if(l==r) return l;int num=max(0,min(R,mid)-max(L,l)+1-sum[ls[p]]);
	return num>=k ? find(ls[p],k,l,mid) : find(rs[p],k-num,mid+1,r);
}
inline void work1(int x){
	int now=(id.find(x)==id.end() ? x : id[x]);
	ans=now-L+1-ask(rt,now); ins(rt,now); id[x]=--L;id2[L]=x;	
}
inline void work2(int x){
	int now=(id.find(x)==id.end() ? x : id[x]);
	ans=now-L+1-ask(rt,now); ins(rt,now); id[x]=++R;id2[R]=x;
}
inline void change(int x,int y){
	int now=(id.find(x)==id.end() ? x : id[x]);
	ans=now-L+1-ask(rt,now); id[y]=now; id2[now]=y;
}
inline void ask(int x){
	ans=find(rt,x);ans=(id2.find(ans)==id2.end() ? ans : id2[ans]);
}
signed main(){
	rd(n);rd(m);L=1,R=n;
	while(m--){
		int pd,x,y;rd(pd);rd(x);
		if(pd==1) rd(y),change(x-ans,y-ans),printf("%d\n",ans);
		if(pd==2) work1(x-ans),printf("%d\n",ans);
		if(pd==3) work2(x-ans),printf("%d\n",ans);
		if(pd==4) ask(x-ans),printf("%d\n",ans);
	}
}