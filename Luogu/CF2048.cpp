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
#define int long long

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int maxn = 500005;

int n, L, R, k;

int sum[maxn];

int st[maxn][30];

inline void build () {
	for (int i = 1; i <= n; i++) {
		st[i][0] = i;
	}
	int len=log2(n);
	for (int j = 1; j <= len; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			if (sum[st[i][j - 1]] > sum[st[i + (1 << (j-1))][j - 1]]) {
				st[i][j] = st[i][j - 1];
			} else {
				st[i][j] = st[i + (1 << (j-1))][j - 1];
			}
		}
	}
}

inline int query (int l, int r) {
	int len = log2 (r - l + 1);
	if (sum[st[l][len]] > sum[st[r - (1 << len) + 1][len]]) {
		return st[l][len];
	} else {
		return st[r - (1 << len) + 1][len];
	} 
}

struct Node{
	int o, l, r, t;
	
	friend bool operator < (const Node& a, const Node& b) {
		return sum[a.t] - sum[a.o - 1] < sum[b.t] - sum[b.o - 1];		
	}
	friend bool operator > (const Node& a, const Node& b) {
		return sum[a.t] - sum[a.o - 1] > sum[b.t] - sum[b.o - 1];		
	}	
};

priority_queue<Node> q;

signed main () {
	fastread
	
	cin >> n >> k >> L >> R;	
	
	for (int i = 1; i <= n; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	
	build ();
	
	for (int i = 1; i <= n; i++) {
		if (i + L - 1 <= n) {
			q.push(Node{i, i + L - 1, min(i + R - 1, n), query(i + L - 1, min(i + R - 1, n))});
		}
	}
	
	int ans = 0;
	
	while (k --) {
		int o = q.top().o; 
		int l = q.top().l;
		int r = q.top().r;
		int t = q.top().t;
		q.pop();
		
		ans += sum[t] - sum[o - 1];
		
		if(l<=t-1)q.push (Node{o, l, t - 1, query(l, t - 1)});
		if(r>=t+1)q.push (Node{o, t + 1, r, query(t + 1, r)});
	} 
	
	cout << ans << endl; 
		
	return 0;
}
