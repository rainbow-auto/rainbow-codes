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

const int maxn = 200005;

int n, m;
long long d;

struct Node {
	long long mx;
} tr[maxn << 3];

void build (int now, int l, int r) {
	if (l == r) {
		tr[now].mx = 0ll;
		return;
	}

	int mid = (l + r) >> 1;

	build (now << 1, l, mid);
	build (now << 1 | 1, mid + 1, r);
}

void modify (int now, int l, int r, int pos, long long val) {
	if (l == r) {
		tr[now].mx = val;
		return ;
	}

	int mid = (l + r) >> 1;

	if (pos <= mid) { modify (now << 1, l, mid, pos, val); }
	else { modify (now << 1 | 1, mid + 1, r, pos, val); }

	tr[now].mx = max (tr[now << 1].mx, tr[now << 1 | 1].mx);
}

long long query (int now, int l, int r, int L, int R) {
	if (L <= l and r <= R) {
		return tr[now].mx;
	}

	int mid = (l + r) >> 1;
	
	long long res = 0ll;
	if (L <= mid) { res = max ( res, query (now << 1, l, mid, L, R) ); }
	if (R > mid) { res = max ( res, query (now << 1 | 1, mid + 1, r, L, R) ); }

	return res;
}

struct Query {
	char op;
	long long x;
};
vector <Query> qs;

int main () {
	// fastread

	cin >> m >> d;

	while (m --) {
		char op; long long x; cin >> op >> x;
		qs.push_back ( Query { op, x } );
		if (op == 'A') { n ++; }
	}

	build (1, 1, n);

	long long last = 0;
	int len = 0;
	for (auto q : qs) {
		if (q.op == 'A') {
			modify (1, 1, n, ++len, (q.x + last) % d);
		} else if (q.op == 'Q') {
			last = query (1, 1, n, len - q.x + 1, len);
			cout << last << endl;
		}
	}

	return 0;
}
