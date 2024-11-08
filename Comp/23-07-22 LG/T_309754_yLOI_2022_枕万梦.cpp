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
#define int long long

using namespace std;

struct Node {
    int val1, val2;
    int id;

    friend bool operator < (Node x, Node y) {
        if (x.val1 != y.val1) {return x.val1 < y.val1;}
        else {return x.val2 < y.val2;}
    }
};

int n, m;
vector<Node> a;

int main () {
	fastread
	
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int now; cin >> now;

        a.push_back (Node{now, now * i, i});
    }

    sort (a.begin(), a.end());

    for (int i = 0; i < a.size(); i++) {
        cout << a[i].id << " ";
    }

	return 0;
}
