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
#define maxn 100010

using namespace std;

int n;
double arr[maxn];
double sum;
int main () {
//	fastread
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
		sum+=arr[i];
	}
	sum/=(n+1);
	printf("%.7lf ",sum*2);
	for(int i=2;i<=n;++i){
		printf("%.7lf ",sum);
	}
	return 0;
}
