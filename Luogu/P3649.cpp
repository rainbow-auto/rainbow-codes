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

const int maxn = 300005;

namespace Palindrome_Automaton {
	struct Node {
		int cnt, len;
		int next[26];
		int fail;
	};
	Node pam[maxn];

	int cnt, last;

	inline void init() {
		cnt = 1, last = 0; // 奇根
		pam[0].len = 0;
		pam[1].len = -1; // 加入两个恰好变成1
		pam[0].fail = 1; // 偶根的fail是奇根 ()
	}

	#define get_fail(x) while (s[i] != s[i - pam[x].len - 1]) { x = pam[x].fail; }

	inline void insert (string s) {
		for (int i = 0; i < s.size(); i++) {
			int a = last; get_fail(a);
			
			if (not pam[a].next[s[i] - 'a']) {
				int b = pam[a].fail; get_fail(b);
				
				cnt ++;
				pam[cnt].fail = pam[b].next[s[i] - 'a'];
				pam[cnt].len = pam[a].len + 2;
				pam[a].next[s[i] - 'a'] = cnt;
			}
			last = pam[a].next[s[i] - 'a'];
			pam[last].cnt ++;
		}
	}

	inline void solve (string s) {
		insert(s);
		
		for (int i = cnt; i >= 1; i--) {
			pam[pam[i].fail].cnt += pam[i].cnt;
		}

		long long ans = 0;
		for (int i = 1; i <= cnt; i++) {
			ans = max (ans, 1ll * pam[i].len * pam[i].cnt);
		}
		cout << ans << endl;
	}	
}

int main () {
	fastread
	
	string s; cin >> s;
	Palindrome_Automaton::init();
	Palindrome_Automaton::solve(s);

	return 0;
}
