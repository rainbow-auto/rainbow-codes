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

const int maxn = 500005;

namespace Palindrome_Automaton {
	struct Node {
		int len, cnt;
		int next[26];
		int fail;
	};
	Node pam[maxn];

	int cnt, last;

	inline void init () {
		cnt = 1, last = 0; // 奇根的前一个是偶根
		pam[0].len = 0;
		pam[1].len = -1; // 两边同时加入一个
		pam[0].fail = 1; // 奇根不会有fail 
	}

	#define decrypt(x) (s[i] + pam[last].cnt - 97) % 26 + 97
	#define get_fail(x) while (s[i] != s[i - pam[x].len - 1]) { x = pam[x].fail; }

	inline vector<int> solve (string s) {
		vector<int> res;
		
		for (int i = 0; i < s.size(); i++) {
			if (i >= 1) { s[i] = decrypt(i); }

			int a = last; get_fail(a);

			if (not pam[a].next[s[i] - 'a']) { // 没有就新建节点
				int b = pam[a].fail; get_fail(b);
				
				cnt ++;
				pam[cnt].fail = pam[b].next[s[i] - 'a'];
				pam[cnt].cnt = pam[pam[cnt].fail].cnt + 1;
				pam[cnt].len = pam[a].len + 2;
				pam[a].next[s[i] - 'a'] = cnt;
			}

			last = pam[a].next[s[i] - 'a'];

			res.push_back(pam[last].cnt);
		}
		return res;
	}
}

int main () {
	fastread
	
	Palindrome_Automaton::init();
	string s; cin >> s;
	vector<int> res = Palindrome_Automaton::solve(s);
	for (auto x : res) { cout << x << " "; } cout << endl; 

	return 0;
}
