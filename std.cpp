#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
struct line{
	ll l,r;
	// bool operator<(const line &x)const{return this->l!=x.l?this->l<x.l:this->r<x.r;}
	friend bool operator < (Line a, Line b) {
		if (a.l != b.l) { return a.l < b.l; }
		else { return a.r < b.r; }
	}
}a[3005];
ll f[3005],ans=LONG_LONG_MAX;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i].l,&a[i].r);
	sort(a+1,a+1+n);
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	a[0].r=-2e9;
	for(int i=1;i<=n;i++){
		ll tot=-2e9;
		for(int j=i-1;j>=0;j--){
			if(a[j].r>=a[i].l||a[j].r<tot)continue;
			f[i]=min(f[i],f[j]+a[i].r-a[i].l);
			tot=max(tot,a[j].l);
		}
	}

	for (int i = 1; i <= n; i++) { std::cerr << f[i] << " "; } std::cerr << "\n";

	for(int i=1;i<=n;i++){
		if(a[i].r>=a[n].l)ans=min(ans,f[i]);
	}
	printf("%lld",ans);
	return 0;
}
