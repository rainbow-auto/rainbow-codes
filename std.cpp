#include<bits/stdc++.h>//P1966 火柴排队
using namespace std;
#define re register
#define ll long long
#define il inline
#define dou double
#define un unsigned
il ll read()
{
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
#define N 100000+10
#define M 99999997
int n,ans;
struct number
{
	ll val,num;
};
number a[N],b[N];
ll bit[N],x[N];
il bool cmp(number x,number y)
{
	if(x.val==y.val)
		return x.num<y.num;
	return x.val<y.val;
}
il ll lowbit(int x)
{
	return x&(-x);
}
il void change(int x,int d)
{
	for(re int i=x;i<=n;i+=lowbit(i))
	{
		bit[i]+=d;
		bit[i]%=M;
	}	
}
il ll query(int x)
{
	if(x==0)
		return 0;
	ll ret=0;
	for(re int i=x;i>=1;i-=lowbit(i))
	{
		ret+=bit[i];
		ret%=M;
	}	
	return ret;
}
int main()
{
	n=read();
	for(re int i=1;i<=n;i++)
	{
		a[i].val=read();
		a[i].num=i;
	}
	for(re int i=1;i<=n;i++)
	{
		b[i].val=read();
		b[i].num=i;
	}
	for (int i = 1; i <= n; i++) { std::cerr << a[i].num << ' '; } std::cerr << "\n";
	for (int i = 1; i <= n; i++) { std::cerr << b[i].num << ' '; } std::cerr << "\n";
	
	std::cerr << "\n";

	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	
	for (int i = 1; i <= n; i++) { std::cerr << a[i].num << ' '; } std::cerr << "\n";
	for (int i = 1; i <= n; i++) { std::cerr << b[i].num << ' '; } std::cerr << "\n";
	
	for(re int i=1;i<=n;i++)
		x[a[i].num]=b[i].num;
	for(re int i=1;i<=n;i++)
	{
		change(x[i],1);
		ans+=i-query(x[i]);
		ans%=M;
	}
	cout<<ans<<endl;
	return 0;
}
