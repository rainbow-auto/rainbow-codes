#include<bits/stdc++.h>
#define int long long
#define ll long long
#define next nxt
#define re register
#define il inline
const int N = 65;
const int M = 1463;
using namespace std;
int max(int x,int y){return x > y ? x : y;}
int min(int x,int y){return x < y ? x : y;}


namespace Task1 {
    const int maxn = 10005;
    int mem[maxn];
    
    int f (int x) {
        if (mem[x]) { return mem[x]; }
        if (x < 10) { mem[x] = x * x; return mem[x]; }
        mem[x] = f (x / 10) + (x % 10) * (x % 10); return mem[x];
    }

    int solve (int l, int r, int k) {
        int res = 0;
        for (int i = l; i <= r; i++) {
            if (f(i) * k == i) { res ++; }
        }
        return res;
    }
}

int T,k,l,r,cnt;
int f[N][M],a[20];

il int read()
{
	int f=0,s=0;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f |= (ch=='-');
	for(; isdigit(ch);ch=getchar()) s = (s<<1) + (s<<3) + (ch^48);
	return f ? -s : s;
}

il int dfs(int len,int sum,int num,bool bound)
{
	if(!len)
	{
		if(sum * k == num) return 1;
		else return 0;
	}
	if(f[len][sum] != -1) return f[len][sum];
	int lim = 9 , ans = 0;
	if(bound) lim = min(lim,a[len]);
	for(re int i=0;i<=lim;i++)
		ans += dfs(len-1,sum+i*i,num*10+i,(bound && i==lim));
	return f[len][sum] = ans;
}

il int Get_Ans(int x)
{
	memset(f , -1 , sizeof f);
	cnt = 0;
	while(x) { a[++cnt] = x % 10 , x /= 10; }
	reverse(a+1,a+cnt+1);
	return dfs(cnt,0,0,1);
}

il int Main()
{
	k = read() , l = read() , r = read();
//	cout << Get_Ans(r) - Get_Ans(l-1) << "\n";	

	cout << Task1::solve(l, r, k) << endl;

	if (Get_Ans(r) - Get_Ans(l - 1) != Task1::solve(l, r, k)) {
		return 114514;
	} else {
		return 0;
	}
}

signed main()
{
	return Main();
}

