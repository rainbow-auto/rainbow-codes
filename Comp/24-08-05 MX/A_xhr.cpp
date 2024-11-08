#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

#pragma GCC Optimize(2)

#define endl "\n"

using namespace std;
long long read()
{
	long long ans = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;
}
long long c,n,k,pos;
long long nums[500010],s[500010],qz[500010],ans[500010];

// __gnu_pbds::gp_hash_table <long long,long long> p;

int main()
{
	freopen("rank.in","r",stdin);
	freopen("rank.out","w",stdout);
	c = read(); n = read(); k = read();
	for(long long i = 1;i <= n;i++)
	{
		nums[i] = read();
		s[i] = nums[i];
	}
	sort(s + 1,s + 1 + n);
	for(int i = 1;i <= n;i++)
	{
		qz[i] = qz[i - 1] + s[i];
	}
	for(int i = 1;i <= n;i++)
	{
		// if(p.find (nums[i]) != p.end ())
		// {
		// 	cout << ans[p[nums[i]]] << endl;
		// 	continue;
		// }
		// p[nums[i]] = ++pos;
        pos ++;
		long long x1 = lower_bound(s + 1,s + 1 + n,nums[i]) - s; int x2 = upper_bound(s + 1,s + 1 + n,nums[i]) - s;
		long long g = n - (x1 - 1); long long f = n - (x2 - 1) + 1;
		if(g < k)
		{
			long long cha = k - g;
			long long now = qz[x1 - 1] - qz[x1 - 1 - cha];
			long long to = nums[i]* cha;
			ans[pos] = to - now;
		}
		else if(f > k)
		{
			long long to = s[n - k + 1];
			ans[pos] = to - nums[i];
		}
		else
		{
			ans[pos] = 0;
		}
		cout << ans[pos] << "\n";
	}
	return 0;
}