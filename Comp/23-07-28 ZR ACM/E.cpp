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

int d,t;
char ch;

int main () {
	fastread
	for(int i=1;i<=5;++i){
		cin>>ch;
		if(ch=='T')t++;
		else if(ch=='D')d++;
	}
	if(d==3)cout<<"DRX";
	else cout<<"T1";
	return 0;
}
