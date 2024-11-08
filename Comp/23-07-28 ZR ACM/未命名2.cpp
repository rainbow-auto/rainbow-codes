#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define mid ((l+r)>>1)
const int maxn=3010;
using namespace std;
struct tree{
	int ls,rs,val;
}t[maxn*32*32];
int root[maxn*maxn],cnt;
void modify(int &p,int lsp,int l,int r,int pos,int v){
	if(!p)p=++cnt;
	if(l==r)t[p].val=max(t[p].val,v);
	if(mid>=pos)modify(t[p].ls,l,mid,pos,v);
	else modify(t[p].rs,mid+1,r,pos,v);
}

int main ()
{

	return 0;
}

