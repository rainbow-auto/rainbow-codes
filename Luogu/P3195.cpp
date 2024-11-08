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

#define fastread std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

#define int long long

// using namespace std;

using std::cin;
using std::cout;

const int maxn = 50005;

int n, L;

double c[maxn];
double sum[maxn], dp[maxn];
int q[maxn], begin, end;

inline double a (int i) { return sum[i] + i; }
inline double b (int i) { return sum[i] + i + 1 + L; }
inline double X (int i) { return b(i); }
inline double Y (int i) { return b(i) * b(i) + dp[i]; }

inline double k (int i, int j) { return (Y(i) - Y(j)) / (X(i) - X(j)); } // 算斜率

signed main () {
	fastread

	cin >> n >> L;

	for (int i = 1; i <= n; i++) { cin >> c[i]; }

	for (int i = 1; i <= n; i++) { sum[i] = sum[i - 1] + c[i]; }

	begin = 1, end = 1; // 保证 begin < end 不成立 (空队列)
	for (int i = 1; i <= n; i++) {
		while (begin < end and k(q[begin], q[begin + 1]) < 2 * a(i)) { begin ++; }
		dp[i] = dp[q[begin]] + ( a(i) - b(q[begin]) ) * ( a(i) - b(q[begin]) );
		while (begin < end and k(i, q[end - 1]) < k(q[end - 1], q[end]) ) { end --; }
		q[++end] = i;
	}

	cout << (int)dp[n] << endl;

	return 0;
}
