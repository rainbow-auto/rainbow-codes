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

string s;

int main () {
	fastread
	
    cin >> s;

    int digit = 0, lower = 0, upper = 0;
	for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) digit ++;
        if (islower(s[i])) lower ++;
        if (isupper(s[i])) upper ++;
    }

    cout << digit << " " << lower << " " << upper << endl;
    
    return 0;
}
