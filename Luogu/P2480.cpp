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

// ↓↓↓ 常数大小为inf的源头
#define int __int128

const int maxn = 50005;
const int mod[] = {0, 2, 3, 4679, 35617, 999911658}; // 最后一个是前面几个乘起来 - 1 (欧拉定理)

inline int ksm (int a, int b, int p) {
	int base = a;
	int res = 1;

	while (b) {
		if (b & 1) { res = res * base % p; }
		base = base * base % p;
		b >>= 1;
	} 

	return res;
}

int frac[maxn];
inline void get_frac(int p) {
	frac[0] = 1;
	for (int i = 1; i <= p; i++) {
		frac[i] = (frac[i - 1] * i) % p;
	}
}

inline int inv (int x, int p) { return ksm(x, p - 2, p); } // 人形自走大常数生成器

inline int C(int n, int m, int p) {
	if (n < m) { return 0; }
	return frac[n] * inv(frac[m], p) % p * inv(frac[n - m], p) % p;  
}

inline int lucas (int n, int m, int p) {
	if (n < m) { return 0; }
	if (not n) { return 1; }
	else { return lucas(n / p, m / p, p) * C(n % p, m % p, p) % p; }
}

inline int crt (const int a[]) {
	int res = 0;
	for (int i = 1; i <= 4; i++) {
		res = (res + a[i] * (mod[5] / mod[i]) % mod[5] * inv(mod[5] / mod[i], mod[i])) % mod[5]; // 就是对于mod != mod[i]的方程, (mod[5]/mod[i]) 对于它取模都是0, 只有mod等于i时才正好=a[i]
	}
	return res;
}

signed main () {
	fastread
	

	long long _n, _g;

	cin >> _n >> _g;

	int n = (__int128) _n;
	int g = (__int128) _g;

	// 特判
	if (g % (mod[5] + 1) == 0) { cout << 0 << endl; return 0; } // mod + 1 是因为我们根据欧拉定理在求幂时把它减1了

	int a[5]; memset (a, 0, sizeof(a));

	for (int m = 1; m <= 4; m++) {
		get_frac(mod[m]); // 阶乘初始化
		
		for (int i = 1; i * i <= n; i++) { // sqrt(n)枚举因数 (其实根本跑不满, 1e9的情况下, d是1e3左右)
			if (n % i != 0) { continue; }
			a[m] = (a[m] + lucas (n, i, mod[m])) % mod[m];
			if (i * i == n) { continue; }
			a[m] = (a[m] + lucas (n, n / i, mod[m])) % mod[m]; // 两个因数
		}
	}

	int sum = crt (a);

	cout << (long long) ksm (g, sum, mod[5] + 1) << endl; // +1的理由同上

	return 0;
}
