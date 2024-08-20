#include <cstdio>
#include <vector>

typedef long long ll;

const int maxn = 100005, maxk = 104, mod = 1000000007;
int f[maxn][maxk][2][2];
int g[maxk][2][2];
int lim[maxn];
std::vector<int> G[maxn];

inline void __a(int &x) { if(x >= mod) x -= mod; }

int N, K;
void dp(int u, int fa) {
	f[u][0][0][0] = 1;
	f[u][1][1][0] = 1;
	lim[u] = 1;

	for(int v : G[u])
		if(v != fa) {
			dp(v, u);

			int nlim = std::min(lim[u] + lim[v], K);
			for(int a = 0; a <= lim[u]; a ++)
				for(int b = 0; b <= lim[v] and a + b <= nlim; b ++) {
					for(int pre1 = 0; pre1 < 2; pre1 ++)
					for(int pre2 = 0; pre2 < 2; pre2 ++)
					for(int t1 = 0; t1 < 2; t1 ++)
					for(int t2 = 0; t2 < 2; t2 ++)
						if((t2 | pre1)) 
						__a(g[a + b][pre1][pre2 | t1] += 1ll * f[u][a][pre1][pre2] * f[v][b][t1][t2] % mod);
				}

			for(int k = 0; k <= nlim; k ++)
				for(int p = 0; p < 2; p ++)
					for(int q = 0; q < 2; q ++)
						f[u][k][p][q] = g[k][p][q];
			for(int k = 0; k <= nlim; k ++)
				g[k][0][0] = g[k][0][1] = g[k][1][0] = g[k][1][1] = 0;
			lim[u] = nlim;
		}
}

int main() {
	scanf("%d %d", &N, &K);
	for(int i = 1; i < N; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dp(1, 0);
	printf("%d\n", (f[1][K][0][1] + f[1][K][1][1]) % mod);
}