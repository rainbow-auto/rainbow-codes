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

using std::cin;
using std::cout;

#define fastread std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

const int maxn = 500005;
const int maxm = 31;

int n, m;
int sum[maxn];

struct Trie {

	struct Node {
		int ch[2];
		int cnt; // 经过这个节点的数
	};

	Node trie[maxn * (maxm + 5) + 10];
	int tot;
	inline int newNode () { return ++tot; }
	
	int root[maxn];

	void _insert (int now, int old, int val) {
		for (int i = maxm; i >= 0; i--) {
			trie[now].cnt = trie[old].cnt + 1; // 经过这个节点的数增加了1
			
			bool num = (val & (1 << i));
			
			if (not trie[now].ch[num]) { trie[now].ch[num] = newNode (); } // 新建节点
			trie[now].ch[num ^ 1] = trie[old].ch[num ^ 1];

			now = trie[now].ch[num];
			old = trie[old].ch[num];
		}

		trie[now].cnt = trie[old].cnt + 1; // 不要忘记更新最后一个节点的 cnt
	}	

	int _query (int l, int r, int val) {
		int res = 0;
		for (int i = maxm; i >= 0; i--) {
			bool num = (val & (1 << i));

			if (trie[ trie[r].ch[num ^ 1] ].cnt - trie[ trie[l].ch[num ^ 1] ].cnt) {
				l = trie[l].ch[num ^ 1];
				r = trie[r].ch[num ^ 1];
				res += (1 << i);
			} else {
				l = trie[l].ch[num];
				r = trie[r].ch[num];
			}
		}	

		return res;
	}

	inline void insert (int id, int val) {
		root[id] = newNode ();
		_insert (root[id], root[id - 1], val);
	}

	inline int query (int l, int r, int val) {
		if (l == 0) { return std::max ( val, _query (root[0], root[r], val) ); }
		else { return _query (root[l - 1], root[r], val); }
	}

} tr;

int main () {
	fastread

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int val; cin >> val;
		sum[i] = sum[i - 1] xor val;
	}
	
	for (int i = 1; i <= n; i++) { tr.insert (i, sum[i]); }

	while (m --) {
		char op; cin >> op;

		if (op == 'A') {
			int val; cin >> val;
			n ++; sum[n] = sum[n - 1] xor val;
			tr.insert (n, sum[n]);
		} else if (op == 'Q') {
			int l, r, val; cin >> l >> r >> val;
			cout << tr.query (l - 1, r - 1, sum[n] xor val) << endl;
		}
	}

	return 0;
}