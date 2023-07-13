#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

#define maxn 100010

struct tree{
	int l,r,val,key,size;
}fhq[maxn];

int cnt,root;

inline int newnode(int val){
	cnt++;
	fhq[cnt].val=val;
	fhq[cnt].size=1;
	fhq[cnt].key=rand();
	return cnt;
}

inline void update(int now){
	fhq[now].size=fhq[fhq[now].l].size+fhq[fhq[now].r].size+1;
}

void split(int now,int val,int &x,int &y){//<=val >val
    //cout<<now<<" "<<fhq[now].val<<'\n';
	if(!now)x=y=0;
	else{
		if(fhq[now].val>val){
			y=now;
			split(fhq[now].l,val,x,fhq[now].l);
		} 
		else{
			x=now;
			split(fhq[now].r,val,fhq[now].r,y);
		}
		update(now);
	}
}

int merge(int x,int y){
	if(!x||!y)return x+y;
	if(fhq[x].key<fhq[y].key){
		fhq[x].r=merge(fhq[x].r,y);
		update(x);
		return x;
	}
	else{
		fhq[y].l=merge(x,fhq[y].l);
		update(y);
		return y;
	}
}

int x,y,z;

inline void insert(int val){
//	cout<<root<<'\n';
	split(root,val,x,y);
//	cout<<x<<" "<<y<<'\n';
	x=merge(x,newnode(val));
//	cout<<x<<'\n';
	root=merge(x,y);
//	cout<<root<<'\n';
}

inline void remove(int val){
	split(root,val,x,y);
	split(x,val-1,x,z);
	z=merge(fhq[z].l,fhq[z].r);
	root=merge(merge(x,z),y);
}

inline int getrank(int val){
	split(root,val-1,x,y);
//	cout<<"QAQ\n";
	int res=fhq[x].size+1;
	root=merge(x,y);
	return res;
}

inline int getnum(int rk){
	int now=root;
	while(now){
		if(fhq[fhq[now].l].size+1==rk)return fhq[now].val;
		if(fhq[fhq[now].l].size>=rk)now=fhq[now].l;
		else rk-=fhq[fhq[now].l].size+1,now=fhq[now].r;
	}
}

inline int suf(int val){
	split(root,val,x,y);
	int now=y;
	while(now){
		if(!fhq[now].l)break;
		now=fhq[now].l;
	}
	root=merge(x,y);
	return fhq[now].val;
}

inline int pre(int val){
    split(root,val-1,x,y);
	int now=x;
	while(now){
		if(!fhq[now].r)break;
		now=fhq[now].r;
	}
	root=merge(x,y);
	return fhq[now].val;
}

int n;

int op,qwq;

int main ()
{
//	fastread
	cin>>n;
	while(n--){
		cin>>op>>qwq;
		if(op==1)insert(qwq);
		else if(op==2)remove(qwq);
		else if(op==3)cout<<getrank(qwq)<<'\n';
		else if(op==4)cout<<getnum(qwq)<<'\n';
		else if(op==5)cout<<pre(qwq)<<'\n';
		else if(op==6)cout<<suf(qwq)<<'\n';
	}
	return 0;
}
