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

int n;
int to[maxn];

bool vis[maxn];
stack <int> s;

vector <int> ans;
bool vis2[maxn], flag;
void find_ans (int now) {
	if (vis2[now]) return;
	vis2[now] = true; 
	ans.push_back(now);
	find_ans(to[now]);
}

void dfs (int now) {
	vis[now] = true;	
 
    int t = to[now];
    if (not vis[t]) {
		dfs (t);
	} else {
		find_ans (t);	
		flag = true;
	}
}

int main () {
//	fastread
	
    cin >> n;
    for (int i = 1; i <= n; i++) {cin >> to[i];}
    
    memset (vis, 0, sizeof (vis));

    for (int i = 1; i <= n; i++) {
        if (not vis[i]) {
            dfs (i);
            
            if (not ans.empty()) {
                cout << ans.size() << endl;
                for (int i = 0; i < ans.size(); i++) {cout << ans[i] << " ";}
                cout << endl;
				break;
        	}
		}
    }

	return 0;
}
