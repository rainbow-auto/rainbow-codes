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
#include <random>

#define fastread ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const int maxn = 205;

int n, m;
char a[maxn][maxn];
int vis[maxn][maxn];

mt19937 myrand(114514);

int cntnow = 0;

void dfs (int nowx, int nowy, int dirnow) {
    if (nowx < 1 or nowx > n or nowy < 1 or nowy > m) return;
    
    cntnow ++;

    if (cntnow >= 400005) return; 
	if (vis[nowx][nowy] >= 2) return;
	 
	if (a[nowx][nowy] == '.') {
    	vis[nowx][nowy]++;
	}

    if (a[nowx + dx[dirnow]][nowy + dy[dirnow]] == '#') {
        int dir[] = {0, 1, 2, 3};
        shuffle (dir, dir + 4, myrand);
        
        for (int i = 0; i < 4; i++) {
            dfs (nowx + dx[dir[i]], nowy + dy[dirnow], dir[i]);    
        }
    } else {
        dfs (nowx + dx[dirnow], nowy + dy[dirnow], dirnow);
    }
}

int main () {
	fastread
    
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    } 

    vis[2][2] = true;

    int dir[] = {0, 1, 2, 3};
    shuffle (dir, dir + 4, myrand);
    
    for (int i = 0; i < 4; i++) {
        dfs (2 + dx[dir[i]], 2 + dy[dir[i]], dir[i]);    
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans ++;
        }
    }

    cout << ans << endl;

	return 0;
}
