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

const int maxn = 400005;
const int sqrt_n = 650;

int m;
int n, tot; // tot: 离散化以后的数量
int a[maxn], b[maxn]; // b: 离散化以后的数组

int len, belong[maxn], L[maxn], R[maxn];

int t[maxn]; // 桶

int p[sqrt_n][sqrt_n]; // p[i][j] : 块 i 到块 j 的众数
int cnt[sqrt_n][maxn]; // cnt[i][j] : 前 i 个块, j出现的次数

inline void discretization () {
	for (int i = 1; i <= n; i++) {
		b[i] = a[i]; // 先用 $b$ 暂存 $a$
	}
	
	sort (b + 1, b + n + 1);
	tot = unique (b + 1, b + n + 1) - b - 1;

	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound (b + 1, b + tot + 1, a[i]) - b;
	}
}

inline void init () { // 分块belong初始化
	len = sqrt (n);
	memset (L, 0x3f, sizeof (L));

	for (int i = 1; i <= n; i++) {
		belong[i] = (i - 1) / len + 1;
		L[belong[i]] = min (L[belong[i]], i);
		R[belong[i]] = max (R[belong[i]], i);
	}
	len = belong[n]; // len 更新为最后一个点 (防止出现奇怪的越界)
}

inline void preProcess () { // 预处理
	discretization ();
	init ();

	// 处理 cnt
	for (int i = 1; i <= n; i++) {
		cnt[belong[i]][a[i]] ++;
	}
	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= tot; j++) {
			cnt[i][j] += cnt[i - 1][j]; // 类似前缀和?
		}
	}

	// 处理 p

	for (int i = 1; i <= len; i++) {
		memset (t, 0, sizeof (t)); // 此时显然不能用
		for (int j = i; j <= len; j++) {
			p[i][j] = p[i][j - 1]; // 既然需要扩展当前区间, 就需要先继承前面的区间
			for (int k = L[j]; k <= R[j]; k++) { // 开始扩展当前的区间
				t[a[k]] ++;
				
				if (t[p[i][j]] < t[a[k]] or (t[p[i][j]] == t[a[k]] and p[i][j] > a[k])) { // 存在出现次数更多的 / 出现次数一样但数更小
					p[i][j] = a[k];
				}						
			}
		}
	}

	// cout << "pre process" << endl;
	// for (int i = 1; i <= len; i++) {
	// 	for (int j = 1; j <= len; j++) {
	// 		cout << p[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
}

int main () {
	fastread
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	preProcess ();
	
	int x = 0;
	
	while (m --) {
		int l, r; cin >> l >> r;

		l = (l + x - 1) % n + 1;
		r = (r + x - 1) % n + 1;

		if (l > r) swap (l, r);

		int l_pos = belong[l];
		int r_pos = belong[r];

		if (r_pos - l_pos <= 1) { // 在同一个块里面, 暴力找众数
			int p = 0;

			for (int i = l; i <= r; i++) {
				t[a[i]] ++;
				
				if (t[p] < t[a[i]] or (t[p] == t[a[i]] and p > a[i])) {
					p = a[i];
				}
			}

			// 清空
			for (int i = l; i <= r; i++) {
				t[a[i]] = 0;
			}

			cout << b[p] << endl;
			x = b[p];
		
		} else {
			int res = p[l_pos + 1][r_pos - 1]; // 整块内的众数大小
			t[res] = cnt[r_pos - 1][res] - cnt[l_pos][res]; // 整块内众数的出现次数
			
			// 还要更新一下两边散块出现的数的在整块中出现的次数
			// 为什么不直接t[a[i]] ++ ?
			// 因为一个在整块里本来不是众数的数, 加上两边散块里它的出现次数, 就有可能可能成为新的众数

			for (int i = l; i <= R[l_pos]; i++) {
				if (not t[a[i]]) {
					t[a[i]] += cnt[r_pos - 1][a[i]] - cnt[l_pos][a[i]];
				}
			}
			for (int i = r; i >= L[r_pos]; i--) {
				if (not t[a[i]]) {
					t[a[i]] += cnt[r_pos - 1][a[i]] - cnt[l_pos][a[i]];
				}
			}

			// 暴力统计两边散块
			for (int i = l; i <= R[l_pos]; i++) {
				t[a[i]] ++;		
				
				if (t[res] < t[a[i]] or (t[res] == t[a[i]] and res > a[i])) {
					res = a[i];
				}
			}
			for (int i = r; i >= L[r_pos]; i--) {
				t[a[i]] ++;

				if (t[res] < t[a[i]] or (t[res] == t[a[i]] and res > a[i])) {
					res = a[i];
				}
			}

			for (int i = l; i <= r; i++) {
				t[a[i]] = 0;
			}
			t[p[l_pos + 1][r_pos - 1]] = 0;
			cout << b[res] << endl;
			x = b[res];
		}
	}

	return 0;
}