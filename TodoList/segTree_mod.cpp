#include<bits/stdc++.h>
#define inf LONG_LONG_MAX
#define re register
#define ls ((p)<<1)
#define rs (((p)<<1)|1)
#define mid ((l+r)>>1)
#define int long long
#define maxn 100010
using namespace std;
int T;
int n,m;
int arr[maxn];
int ans;
struct tree{
	int sum,mx,mn;
	int tag;
	bool tag2;
}t[maxn<<2];
inline void pushup(int p){
	t[p].sum=t[ls].sum+t[rs].sum;
	t[p].mn=min(t[ls].mn,t[rs].mn);
	t[p].mx=max(t[ls].mx,t[rs].mx);
}
void build(int p,int l,int r){
	if(l==r){
		t[p].sum=t[p].mx=t[p].mn=arr[l];
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(p);
}
inline void pushdown(int p,int l,int r){
	int ta=t[p].tag;
	t[ls].tag+=ta;
	t[rs].tag+=ta;
	t[ls].mn+=ta;
	t[rs].mn+=ta;
	t[ls].mx+=ta;
	t[rs].mx+=ta;
	t[ls].sum+=ta*(mid-l+1);
	t[rs].sum+=ta*(r-mid);
	t[p].tag=0;
}
void add(int p,int l,int r,int L,int R,int v){
	if(L<=l&&r<=R){
		t[p].mn+=v;
		t[p].mx+=v;
		t[p].sum+=v*(r-l+1);
		t[p].tag+=v;
		return; 
	}
	pushdown(p,l,r);
	if(mid>=L)add(ls,l,mid,L,R,v);
	if(mid<R)add(rs,mid+1,r,L,R,v);
	pushup(p);
}
void Sqrt(int p,int l,int r,int L,int R) {
//	cout<<p<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<'\n';
/*
    if(l==r){
    	t[p].mn=sqrt(t[p].mn);
    	t[p].mx=sqrt(t[p].mx);
    	t[p].sum=sqrt(t[p].sum);
    	return ;
	}
*/
	if(L<=l&&r<=R) {
		if((int)sqrt(t[p].mn)-(int)sqrt(t[p].mx)==(t[p].mn-t[p].mx)){
			int del=t[p].mn-(int)sqrt(t[p].mn);
			t[p].tag-=del;
			t[p].mn-=del;
			t[p].mx-=del;
			t[p].sum-=del*(r-l+1);
//			cout<<p<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<del<<" "<<t[p].mn<<" "<<t[p].mx<<" "<<t[p].sum<<'\n';
			return;
		}
		pushdown(p,l,r);
		Sqrt(ls,l,mid,L,R),Sqrt(rs,mid+1,r,L,R);
		pushup(p);
		return;
	}
	pushdown(p,l,r);
	if(L<=mid) Sqrt(ls,l,mid,L,R);
	if(R>mid) Sqrt(rs,mid+1,r,L,R);
	pushup(p);
}
int query(int p,int l,int r,int L,int R){
	if(L<=l&&r<=R)return t[p].sum;
	pushdown(p,l,r);
	int res=0;
    if(mid>=L)res+=query(ls,l,mid,L,R);
    if(mid<R)res+=query(rs,mid+1,r,L,R);
    return res;
}
int op,a,b,c; 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(re int i=1;i<=n;++i){
    	cin>>arr[i];
	}
	build(1,1,n);
	while(m--){
		cin>>op;
		if(op==1){
			cin>>a>>b>>c;
			add(1,1,n,a,b,c);
		}
		else if(op==2){
			cin>>a>>b;
			Sqrt(1,1,n,a,b);
		}
		else if(op==3){
			cin>>a>>b;
			cout<<query(1,1,n,a,b)<<'\n';
		}
//		cout<<query(1,1,n,1,4)<<'\n';
	}
	return 0;
}