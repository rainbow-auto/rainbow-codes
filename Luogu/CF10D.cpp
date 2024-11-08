#include <iostream>
#include <algorithm>
#include <vector>

const int maxn = 5005;

int n, m;

int a[maxn];
int b[maxn];

int dp[maxn][maxn];

int pre[maxn];
int pre_fa[maxn];

int fa[maxn][maxn];

int main () {

    std::cin >> n;
    for (int i = 1; i <= n; i++) { std::cin >> a[i]; }
    
    std::cin >> m;
    for (int i = 1; i <= m; i++) { std::cin >> b[i]; }

    for (int i = 1; i <= n; i++) {
        // pre process

        int mx = 0, from = 0;

        for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j]; fa[i][j] = j;
		    if (a[i] == b[j]) { 
				if (mx + 1 > dp[i][j]) { dp[i][j] = mx + 1; fa[i][j] = from; }
			}
            if (b[j] < a[i]) { 
				if (mx < dp[i - 1][j]) { from = j; mx = dp[i - 1][j]; }
			}
        }    
    }

	int st = 0;

    int ans = 0;
    for (int j = 1; j <= m; j++) { 
		if (dp[n][j] > ans) {
			ans = dp[n][j];
			st = j;
		}
	}
    std::cout << ans << "\n";

	if (not ans) { return 0; }

	std::vector <int> vec;

	int i = n;

	int now = st;
	while (now or i) {
		if (fa[i][now] != now) { vec.push_back (b[now]); }
		now = fa[i][now]; i--;
	}

	std::reverse (vec.begin (), vec.end ());

	for (auto now : vec) { std::cout << now << " "; } std::cout << "\n";

    return 0;
}