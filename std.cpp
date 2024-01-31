#include <cstdio>
#include <cctype>
#include <iostream>
#define pprint(x) ::print(x),putchar(' ')
#define fprint(x) ::print(x),putchar('\n')
using namespace std;
inline long long read()
{
	long long x = 0;int f = 1;
	char ch = getchar();
	for(;!isdigit(ch);ch = getchar())
		if(ch == '-')
			f = -1;
	for(;isdigit(ch);ch = getchar())
		x = x * 10 + (ch ^ 48);
	return x * f;
}
void print(long long x)
{
	if(x < 0)
		x = -x,putchar('-');
	if(x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}

const int N = 300010,mod = 1000000009,q1 = 691504013,q2 = 308495997,Inv = 276601605;

long long qpow(long long a,int b)
{
	long long ans = 1;
	while(b)
	{
		if(b & 1) ans = ans * a % mod;
		b >>= 1,a = a * a % mod;
	}
	return ans;
}
long long Mod(long long a)
{
	if(a > mod)
		a -= mod;
	else if(a < 0)
		a += mod;
	return a;
}

int n,m;

struct Seg_Tree
{
	long long q,inv,m[N];
	struct tree
	{
		int l,r;
		long long sum,lz;
	}t[N << 2];

	#define ls now << 1
	#define rs now << 1 | 1

	void build(int now,int l,int r)
	{
		t[now].l = l,t[now].r = r;
		t[now].sum = t[now].lz = 0;
		if(l == r)
			return;
		int mid = l + r >> 1;
		build(ls,l,mid),build(rs,mid + 1,r);
	}
	void init(int Q)
	{
		q = Q,inv = qpow(q - 1,mod - 2);
		m[1] = q;
		for(int i = 2;i <= n;i++)
			m[i] = m[i - 1] * q % mod;
		build(1,1,n);
	}

	void pusha(int now,long long a)
	{
		int l = t[now].l,r = t[now].r;
		t[now].lz = Mod(t[now].lz + a);
		t[now].sum = (t[now].sum + Mod(a * m[r - l + 1] % mod - a) * inv) % mod;
	}
	void pushdown(int now)
	{
		if(t[now].lz)
		{
			int l = t[now].l,r = t[now].r,mid = l + r >> 1;
			pusha(ls,t[now].lz);
			pusha(rs,t[now].lz * m[mid - l + 1] % mod);
			t[now].lz = 0;
		}
	}
	void pushup(int now)
	{
		t[now].sum = Mod(t[ls].sum + t[rs].sum);
	}
	void update(int now,int l,int r,int a)
	{
		if(t[now].l == l && t[now].r == r)
		{
			pusha(now,a);
			return;
		}
		pushdown(now);
		int mid = t[now].l + t[now].r >> 1;
		if(r <= mid)
			update(ls,l,r,a);
		else if(l > mid)
			update(rs,l,r,a);
		else
			update(ls,l,mid,a),update(rs,mid + 1,r,a * m[mid - l + 1] % mod);
		pushup(now);
	}
	long long query(int now,int l,int r)
	{
		std::cerr << "now = " << now << " " << t[now].sum << "\n";
        
        if(t[now].l == l && t[now].r == r)
			return t[now].sum;
		pushdown(now);
		int mid = t[now].l + t[now].r >> 1;
		if(r <= mid)
			return query(ls,l,r);
		else if(l > mid)
			return query(rs,l,r);
		else
			return Mod(query(ls,l,mid) + query(rs,mid + 1,r));
		pushup(now);
	}

	#undef ls
	#undef rs
};

Seg_Tree t1,t2;
long long sum[N];

int main()
{
	n = read(),m = read();
	for(int i = 1;i <= n;i++)
		sum[i] = Mod(sum[i - 1] + read());
	t1.init(q1),t2.init(q2);
	while(m--)
	{
		int op = read(),l = read(),r = read();
		if(op == 1)
			t1.update(1,l,r,q1),t2.update(1,l,r,q2);
		else
		{
			std::cerr << "-----------------" << "\n";
            long long a = t1.query(1,l,r);
            std::cerr << "-------" << "\n";
			long long b = t2.query(1,l,r);
			a = Mod(a - b) * Inv % mod;
			fprint(Mod(Mod(a - sum[l - 1]) + sum[r]) % mod);
		}
	}
	return 0;
}

/*
-----------------
now = 1 840528059
-------
now = 1 159471965
-----------------
now = 1 606544086
now = 2 74512022
now = 3 532032064
now = 6 74512023
-------
now = 1 393455946
now = 2 925487992
now = 3 467967963
now = 6 925487993
*/