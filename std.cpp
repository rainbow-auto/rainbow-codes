#include<bits/stdc++.h>

using namespace std;

const int N = 5000 + 5;

inline void checkmax(int &x, int y){
	if(y > x) x = y;
}

inline void checkmin(int &x, int y){
	if(y < x) x = y;
}

int n = 0, m = 0, k = 0, a[N] = {}, f[N] = {};
int g[N][N] = {}, ans = 0;

inline void solve(){
	scanf("%d", &n); m = k = 0;
	for(int i = 1 ; i <= n ; i ++){
		scanf("%d", &a[i]);
		k = g[k][a[i]];
	}
	memset(f, 0x3f, sizeof(f));
	for(int i = 1 ; i <= n ; i ++) a[i] /= k, checkmax(m, a[i]), f[a[i]] = 0;
	for(int x = m ; x >= 1 ; x --) for(int i = 1 ; i <= n ; i ++){
		int y = a[i];
		checkmin(f[g[x][y]], f[x] + 1);
	}
	ans = max(f[1] - 1, 0);
	for(int i = 1 ; i <= n ; i ++) if(a[i] > 1) ans ++;
	printf("%d\n", ans);
}

int T = 0;

int main(){
	for(int x = 0 ; x < N ; x ++) g[x][0] = g[0][x] = g[x][x] = x;
	for(int x = 1 ; x < N ; x ++) for(int y = 1 ; y < x ; y ++) g[x][y] = g[y][x] = g[y][x % y];
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}