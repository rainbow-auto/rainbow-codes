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
	
    int n; cin >> n;
    cin >> s;

    int acnt = 0, bcnt = 0, ccnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {acnt ++;}
        else if (s[i] == 'B') {bcnt ++;}
        else if (s[i] == 'C') {ccnt ++;}
        
        if (acnt >= 1 and bcnt >= 1 and ccnt >= 1) {cout << i + 1 << endl; break;}
    }

	return 0;
}
