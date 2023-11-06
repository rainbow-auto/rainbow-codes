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
int main () {
	read(a),read(b);
    write(a+b);
	return 0;
}
