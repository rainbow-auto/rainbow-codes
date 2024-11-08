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

__int128 n;

#define int __int128

const int mod =1e9+7;
const int inv=166666668;
inline long long qp(int x,int y){
	long long res=1;
	while(y){
		if(y&1){
			res=res*x%mod;
		}
		x=x*x%mod;
		y>>=1;
	}
	return res;
}

inline void read(__int128 &x){
	x=0;
	__int128 f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
	    x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}
__int128 a,b;
void write(__int128 x){
	if(x<0){
		putchar('-');
		x=-x;
	} 
	if(x<10)putchar(x%10+'0');
	else{
		write(x/10);
		putchar(x%10+'0');
	}
}
signed main () {
//	fastread
	read(n);
	write((n*(n-1)%mod*(3*n%mod*n%mod-n+mod+2)%mod)%mod*inv%mod);
	return 0;
}
