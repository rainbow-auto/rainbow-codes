#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

bool solve(int a){
	int tmp=a;
	int tot=0;
	while (a) {
		if (a & 1)tot++;
		a >>= 1;
	}		
	if(tmp%tot)return false;
	return true;
}

int main ()
{
    for(int i=1;i<=1000;++i){
    	if(solve(i)){
    		cout<<i<<'\n';
		}
	}
	return 0;
}

