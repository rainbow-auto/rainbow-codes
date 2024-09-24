#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = 1000005;
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;

int n, A, B;
int fac[maxn], inv[maxn];
int c[maxn], w[maxn], minci[maxn];
int Gs[maxn];

inline int pow(int a, int b)
{
	int ans = 1;
	for(; b; b >>= 1, a = (LL) a * a % mod)
		if(b & 1)
			ans = (LL) ans * a % mod;
	return ans;
}

inline int C(int n, int m)
{
	if(!n)
		return 1;
	if(m < n)
		return 0;
	return (LL) fac[m] * (LL) inv[m - n] % mod * (LL) inv[n] % mod;
}

int main()
{
	scanf("%d%d%d", &n, &A, &B);
	memset(minci, 0x3f, sizeof(minci));
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &c[i], &w[i]);
		minci[c[i]] = min(minci[c[i]], w[i]);
	}
	int minn = 0, minnn = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(minci[i] < minci[minn])
		{
			minnn = minn;
			minn = i;
		}
		else if(minci[i] < minci[minnn])
			minnn = i;
	}
	int gss = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(w[i] + minci[c[i]] <= A)
			w[i] = minci[c[i]];
		if(c[i] == minn && minci[minnn] + w[i] <= B)
		{
			Gs[c[i]]++;
			gss++;
		}
		if(c[i] != minn && minci[minn] + w[i] <= B)
		{
			Gs[c[i]]++;
			gss++;
		}
	}

    std::cerr << "p1: " << minn << "\n";
    std::cerr << "p2: " << minnn << "\n";

    std::cerr << "w1: " << minci[minn] << "\n";
    std::cerr << "w2: " << minci[minnn] << "\n";

    for (int i = 1; i <= n; i++) std::cerr << Gs[i] << " ";
    std::cerr << "\n";

	int ans = 1;
	fac[0] = 1;
	for(int i = 1; i <= n; ++i)
		fac[i] = (LL) i * fac[i - 1] % mod;
	inv[n] = pow(fac[n], mod - 2);
	for(int i = n - 1; ~i; --i)
		inv[i] = (LL) inv[i + 1] * (i + 1) % mod;
	for(int i = 1; i <= n; ++i)
	{
		if(Gs[i])
		{
			ans = (LL) ans * (LL) C(Gs[i], gss) % mod;
			gss -= Gs[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}