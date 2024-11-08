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
const int maxn=10;
int n,m;
struct mons{
	int hp,att,num;
}a[maxn][2];
void hurt(mons &from,mons &to){
	to.hp-=from.att;
	from.hp-=to.att;
}
void fhurt(mons &from,mons &to){
	to.hp+=from.att;
	from.hp+=to.att; 
}
long double ansa,ansb,anst;
int tot=0;
void dfs(bool turn/*0A1B*/,int arest,int brest,long double p){
//	cout<<(turn?"BOB":"ALICE")<<" "<<arest<<" "<<brest<<" ";
//	printf("%.7Lf\n",p);
//	tot++;
//	if(tot==10)exit(0);
	if(arest==0){
		if(brest){
			ansb+=p;
//			cout<<"bobwin ";
//			printf("%.7Lf\n",ansb);
		}
		else {
			anst+=p;
//			cout<<"tie ";
//			printf("%.7Lf\n",anst);
		}
		return;
	}
	else if(brest==0){
		ansa+=p;
//		cout<<"alicewin ";
//		printf("%.7Lf\n",ansa);
		return;
	}
	int qwq=(turn==false?n:m);
	int id=0;
	for(int i=1;i<=qwq;++i){
		if(a[i][turn].hp>0){
			if(a[i][turn].num<a[id][turn].num||!id){
				id=i;
			}
		}
	}
	a[id][turn].num++;
	for(int i=1;i<=(turn==false?m:n);++i){
		if(a[i][turn^1].hp>0){
			int tar=arest,tbr=brest;
//			cout<<(turn?"BOB":"ALICE")<<" "<<id<<" "<<i<<" "<<a[id][turn].hp<<" "<<a[id][turn].att<<" "<<a[i][turn^1].hp<<" "<<a[i][turn^1].att<<'\n';
			hurt(a[id][turn],a[i][turn^1]);
//			cout<<(turn?"BOB":"ALICE")<<" "<<id<<" "<<i<<" "<<a[id][turn].hp<<" "<<a[id][turn].att<<" "<<a[i][turn^1].hp<<" "<<a[i][turn^1].att<<'\n';
			if(a[id][turn].hp<=0)(turn==0?--arest:--brest);
			if(a[i][turn^1].hp<=0)(turn==0?--brest:--arest);
			dfs(turn^1,arest,brest,1.0*p/(turn==false?tbr:tar));
			arest=tar,brest=tbr;
			fhurt(a[id][turn],a[i][turn^1]);
		}
	}
	a[id][turn].num--;
}
int main () {
//	fastread
    cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i][0].hp;
		a[i][0].att=a[i][0].hp;
	}	
	for(int i=1;i<=m;++i){
		cin>>a[i][1].hp;
		a[i][1].att=a[i][1].hp;
	}
	if(n>m)dfs(false,n,m,1);
	else if(n<m)dfs(true,n,m,1);
	else{
		dfs(true,n,m,0.5);
		dfs(false,n,m,0.5);
	}
	printf("%.15Lf\n%.15Lf\n%.15Lf\n",ansa,ansb,anst);
	return 0;
}
