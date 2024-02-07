#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define next nxt
#define re register
#define il inline
const int N = 1e5 + 5;
using namespace std;
int max(int x,int y){return x > y ? x : y;}
int min(int x,int y){return x < y ? x : y;}

int n,m,l,r;
int root,idx;
struct node{
	int l,r;
	int val,rnd;
	int size;
	bool tag;
}tree[N];

il int read()
{
	int f=0,s=0;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f |= (ch=='-');
	for(; isdigit(ch);ch=getchar()) s = (s<<1) + (s<<3) + (ch^48);
	return f ? -s : s;
}

#define lc tree[now].l
#define rc tree[now].r

il int update(int val)
{
	tree[++idx] = {0,0,val,rand(),1,0};
	return idx;
}

inline void push_up(int now) {
    tree[now].size = tree[lc].size + tree[rc].size + 1; 
}

il void push_down(int now)
{
	if(tree[now].tag) {
        swap(tree[now].l,tree[now].r);
        tree[lc].tag ^= 1;
        tree[rc].tag ^= 1;
        tree[now].tag = 0;
    }
}

il void Split(int now,int k,int &x,int &y)//取前k个放在x，后面的放在y
{
	if(!now) { x = y = 0; return ; }
    push_down(now);
    if(k <= tree[lc].size)//第k个在右子树
	{
		y = now;
		Split(lc,k,x,lc);
		push_up(y);
	}
	else
	{
		x = now;
		Split(rc,k-tree[lc].size-1,rc,y);//类似于Get_Val函数的操作
		push_up(x);
	}
}

int Merge(int x,int y)
{
	if(!x || !y) { 
        return x | y;
    } if(tree[x].rnd < tree[y].rnd) {
		push_down(x);
		tree[x].r = Merge(tree[x].r,y);
		push_up(x);
		return x;
	} else {
		push_down(y);
		tree[y].l = Merge(x,tree[y].l);
		push_up(y);
		return y;
	}
}

void Print(int now)
{
	if(!now) { return; }

	push_down(now);
	Print(lc);
	cout << tree[now].val << " ";
	Print(rc);
}

signed main()
{
	srand(time(NULL));
	n = read() , m = read();
	for(re int i=1;i<=n;i++) root = Merge(root,update(i));
	for(re int i=1;i<=m;i++)
	{
		l = read() , r = read();
		int x,y,z;
		Split(root,r,x,z);
		Split(x,l-1,x,y);
		tree[y].tag ^= 1;
		root = Merge(Merge(x,y),z);
	}
	Print(root);
	return 0;
}