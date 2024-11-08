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

const int maxn = 2000005;

struct Trie {
	struct Node{
		int child[10], cnt; // 孩子, 经过这个点的次数
		bool end; // 结尾 
	};

	Node tr[maxn]; 
	int cnt = 0;

	inline bool insert (string s) {
		int pos = 0;
		for (int i = s.size() - 1; i >= 0; i--) { // 要统计后缀, 所以倒序加入
			int now = s[i] - '0';
			if (not tr[pos].child[now]) {
				tr[pos].child[now] = ++cnt;
			}
			tr[pos].cnt ++;
			pos = tr[pos].child[now];
		}

		bool ret;
		if (tr[pos].cnt) { // 成为某个串的后缀
			ret = false;
		} else {
			ret = true;
		} 
		tr[pos].cnt ++;
		tr[pos].end = true;
		
		return ret;
	}	
	
	void clear () {
		memset (tr, 0, sizeof(tr)); cnt = 0;
	}
};
Trie trie;

int n;
map< string, vector<string> > phones;

inline bool cmp (string a, string b) {
	return a.size() > b.size();
}

int main () {
	fastread

	cin >> n;

	for (int i = 1; i <= n; i++) {
		string name; cin >> name;
		int k; cin >> k;

		for (int i = 1; i <= k; i++) {
			string now; cin >> now;
			phones[name].push_back(now);
		}	
	}

	cout << phones.size() << endl;

	for (auto now : phones) {
		vector<string> res; // 存这个朋友的答案

		string name = now.first;
		sort (now.second.begin(), now.second.end(), cmp); // 先加入长度小的再加入长度大的来统计后缀

		for (auto s : now.second) {
			if (trie.insert(s)) { res.push_back(s); }
		}

		cout << name << " " << res.size() << " ";

		for (auto i : res) { cout << i << " "; }
		cout << endl;

		trie.clear();
	}

	return 0;
}
