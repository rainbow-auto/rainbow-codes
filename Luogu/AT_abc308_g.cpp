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

using i64 = long long;

#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0);

const int maxn = 300005;

int n;
i64 a[maxn];

struct Trie {
    i64 tr[maxn << 5][2];
	int tot;
    int siz[maxn << 5];
    
    void insert (i64 val) {
        int now = 0;
        for (int i = 31; i >= 0; i--) {
            bool x = ((val >> i) & 1);
            if (not tr[now][x]) { tr[now][x] = ++tot; }
            now = tr[now][x];
            siz[now]++;
        }
    }

    void del (i64 val) {
        int now = 0;
        for (int i = 31; i >= 0; i--) {
            bool x = ((val >> i) & 1);
            now = tr[now][x];
            siz[now]--;
        }
    }

    i64 query (i64 val) {
        int now = 0;
        i64 ans = 0;

        for (int i = 31; i >= 0; i--) {
            bool x = ((val >> i) & 1);
            if (not siz[tr[now][x]]) { ans |= (1ll << i); now = tr[now][x ^ 1]; }
            else { now = tr[now][x]; }
        }

        return ans;
    }
} trie;

std::vector <i64> tr[maxn << 5];

void modify (int now, int l, int r, int L, int R, i64 val) {
    if (L <= l and r <= R) { tr[now].push_back (val); return; }

    int mid = (l + r) >> 1;
    if (L <= mid) { modify (now << 1, l, mid, L, R, val); }
    if (R > mid) { modify (now << 1 | 1, mid + 1, r, L, R, val); }
}

i64 ans[maxn];

i64 ansnow = (1ll << 31);
void dfs (int now, int l, int r) {
    // std::cerr << "dfs " << now << " [" << l << ", " << r << "]\n";
     
    // std::cerr << "tr " << now << " : "; for (auto x : tr[now]) { std::cerr << x << " "; } std::cerr << "\n";

    i64 old = ansnow;
    for (auto x : tr[now]) { 
		ansnow = std::min (ansnow, trie.query (x)); 
		trie.insert (x);
	}
    
    if (l == r) { 
        ans[l] = ansnow; 
    } else {
        int mid = (l + r) >> 1;
        
        dfs (now << 1, l, mid);
        dfs (now << 1 | 1, mid + 1, r);
    }

    ansnow = old;
	for (auto x : tr[now]) { trie.del (x); }
}

struct Range {
	int l, r;
	i64 val;
};

int main () {
	fastread
	
	std::cin >> n;

	std::map < i64, std::vector <int> > pre;
	std::vector <Range> add;
	std::vector <int> qs;

	for (int i = 1; i <= n; i++) {
		int op; std::cin >> op;

		if (op == 1) {
			i64 x; std::cin >> x;
			pre[x].push_back (i);
		}
		if (op == 2) { 
			i64 x; std::cin >> x;
			add.push_back (Range { pre[x].back (), i - 1, x });
			pre[x].pop_back ();
		}
		if (op == 3) { qs.push_back (i); }
	}

	for (auto now : pre) {
		if (not now.second.size ()) { continue; }
		for (auto x : now.second) {
			add.push_back (Range { x, n, now.first });
		}
	}

	for (auto now : add) { 
		modify (1, 1, n, now.l, now.r, now.val); 
	}

	dfs (1, 1, n);

	for (auto now : qs) { std::cout << ans[now] << "\n"; }

	return 0;
}
