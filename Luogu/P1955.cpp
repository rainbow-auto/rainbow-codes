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

const int maxn = 3e6 + 5;

int T;
int n;

struct Node {
	int x1, x2;
	int op;
	
	int pos;
		
	friend bool operator < (Node a, Node b) {
		if (a.op != b.op) {
			return a.op > b.op; 
		} else {
			return a.pos < b.pos;
		}
	}
};

vector<Node> q;
vector <int> num;

int fa[maxn];
int find (int x) {
	if (fa[x] == x) return fa[x];
	else return fa[x] = find (fa[x]);
}

inline void init () {
	for (int i = 0; i <= num.size(); i++) fa[i] = i;
} 


int main () {
	fastread
	
	cin >> T;
	
	while (T --) {
		q.clear(); num.clear();
		
		cin >> n;
		
		for (int i = 1; i <= n; i++) {
			int x1, x2, op;
			cin >> x1 >> x2 >> op;
			q.push_back(Node{x1, x2, op, i});
			num.push_back(x1);
			num.push_back(x2);
		}
		
		sort (num.begin(), num.end());
				
		for (int i = 0; i < q.size(); i++) {
			q[i].x1 = lower_bound (num.begin(), num.end(), q[i].x1) - num.begin();
			q[i].x2 = lower_bound (num.begin(), num.end(), q[i].x2) - num.begin();
		}		
		
		sort (q.begin(), q.end());
		
		bool flag = false;
		
		init ();
		for (int i = 0; i < q.size(); i++) {
			int x1 = q[i].x1;
			int x2 = q[i].x2;
			int op = q[i].op;
			
			if (op == 1) {
				fa[find(x2)] = find(fa[x1]);
			} else {
				if (find(x1) == find(x2)) {
					cout << "NO" << endl;
					flag = true;
					break;
				} 
			}
		}		
		
		if (not flag) {
			cout << "YES" << endl;
		}
	}	
		
	return 0;
}
