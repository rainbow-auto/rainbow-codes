#include <iostream>
using namespace std;

int T;

int a, b, c;

int main () {
	
	cin >> T;

	while (T--) {
		cin >> a >> b >> c;
		
		if (a + b >= 10 or a + c >= 10 or b + c >= 10) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	
	return 0;
}