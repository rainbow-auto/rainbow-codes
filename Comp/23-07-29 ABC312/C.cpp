#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 200005;

int n, m;
int a[maxn];
int b[maxn];

bool check (int x) {
    int a_cnt = lower_bound(a + 1, a + n + 1, x) - a - 1;
    int b_cnt = m - (lower_bound(b + 1, b + m + 1, x) - b - 1) - 1; 
//    cout << "x = " << x << endl;
//    cout << "a_cnt = " << a_cnt << endl;
//    cout << "b_cnt = " << b_cnt << endl;
//	cout << "check = " << (a_cnt >= b_cnt) << endl;
	
	return a_cnt >= b_cnt;
}

int main () {

    int l = 0, r = 0;
    
    cin >> n >> m;

    for (int i = 1; i <= n; i++) { cin >> a[i]; r = max (r, a[i]);}
    sort (a + 1, a + n + 1);

    for (int i = 1; i <= m; i++) { cin >> b[i]; r = max (r, b[i]);} 
    sort (b + 1, b + m + 1);

//	check(110); 
	
	int ans = 1e9 + 7;
	for (int i = 1; i <= n; i++) {
		if (check(a[i])) {
			ans = min (ans, a[i]);
		}
	}
	
	for (int i = 1; i <= m; i++) {
		if (check(b[i])) {
			ans = min (ans, b[i]);
		}
	}
	
	cout << ans << endl;
		
    return 0;
}
