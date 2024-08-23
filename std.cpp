#include<bits/stdc++.h>
#define inl inline
#define reg register
#define int long long
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,x,y) for(reg int i=x;i<=(y);++i)
#define per(i,x,y) for(reg int i=x;i>=(y);--i)
#define rpr(i,x,y,z) for(reg int i=x;i<=(y);i+=z)
#define epe(i,x,y,z) for(reg int i=x;i>=(y);i-=z)
#define repe(i,x,y) for(i=x;i<=(y);++i)
#define endl '\n'
#define INF 1e16
#define pb push_back
#define fi first
#define se second
#define lcm(x,y) x/__gcd(x,y)*y
#define ull unsigned long long
#define prr make_pair
#define pii pair<int,int>
#define gt(s) getline(cin,s)
#define at(x,y) for(reg auto x:y)
#define ff fflush(stdout)
#define mt(x,y) memset(x,y,sizeof(x))
#define idg isdigit
#define fp(s) string ssss=s;freopen((ssss+".in").c_str(),"r",stdin);freopen((ssss+".out").c_str(),"w",stdout);
#define sstr stringstream
#define all(x) x.begin(),x.end()
#define mcy(a,b) memcpy(a,b,sizeof(b))
#define ui unsigned
#define si signed
#define eb emplace_back
using namespace std;
const int N=2e5+5,M=25;
int n,q,l[N],u[N],mx[N][M],mn[N][M],lg[N],sx,sy,tx,ty;
pii fl[N][M],fu[N][M],ans;
inl pii calc(int p,int ll,int rr){
	std::cerr << "calc " << p << " " << ll << " " << rr << "\n";

	reg int x=ll;
	per(i,lg[rr-ll+1],0)
		if(mx[x][i]<=p&&p<=mn[x][i]) x+=1ll<<i;
	if(x>rr) return prr(p,rr-ll);
	reg int y=lg[rr-x+1];
	if(p<l[x]){
		reg pii res=calc(fl[x][y].fi,x+(1ll<<y)-1,rr);
		return prr(res.fi,x-ll+l[x]-p+fl[x][y].se+res.se);
	}else{
		reg pii res=calc(fu[x][y].fi,x+(1ll<<y)-1,rr);
		return prr(res.fi,x-ll+p-u[x]+fu[x][y].se+res.se);
	}
}
signed main(){
	fst;
	cin>>n;
	rep(i,1,n){
		cin>>l[i]>>u[i];
		fl[i][0]=prr(mx[i][0]=l[i],0);
		fu[i][0]=prr(mn[i][0]=u[i],0);
	}
	rep(i,2,n) lg[i]=lg[i>>1]+1;
	rep(j,1,20) {
		rep(i,1,n-(1ll<<j)+1){
			mx[i][j]=max(mx[i][j-1],mx[i+(1ll<<(j-1))][j-1]);
			mn[i][j]=min(mn[i][j-1],mn[i+(1ll<<(j-1))][j-1]);
			fl[i][j]=calc(l[i],i,i+(1ll<<j)-1);
			fu[i][j]=calc(u[i],i,i+(1ll<<j)-1);
		}
	}

	cin>>q;
	rep(i,1,q){
		cin>>sx>>sy>>tx>>ty;
		if(sx>tx){
			swap(sx,tx);
			swap(sy,ty);
		}
		ans=calc(sy,sx,tx);
		cout<<ans.se+abs(ans.fi-ty)<<endl;
	}
	return 0;
}