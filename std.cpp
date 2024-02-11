#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>

using namespace std;

template <typename T>
void read(T &x) {
	x = 0; bool f = 0;
	char c = getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f = 1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	if (f) x=-x;
}

const int N = 100050;
int tag[N], siz[N];
int son[N][2], rnd[N];
int val[N], mn[N];

struct node {  
	int pos, num;
	bool operator < (const node &i) const {
		if (num != i.num) return num < i.num;
		return pos < i.pos;
	}
}a[N];
int n;

int rt, x, y, z;
int tot;
int build(int x) {
	val[++tot] = x, mn[tot] = x, siz[tot] = 1;
	rnd[tot] = rand(); return tot;
}

int Mn(int x,int y) {return x < y ? x : y;}

void update(int x) {
	siz[x] = siz[son[x][0]] + siz[son[x][1]] + 1;
	mn[x] = val[x]; 
	if (son[x][0]) mn[x] = Mn(mn[son[x][0]], mn[x]);
	if (son[x][1]) mn[x] = Mn(mn[son[x][1]], mn[x]);
}

void spread(int x) {
	if (!tag[x]) return;
	swap(son[x][0], son[x][1]);
	if (son[x][0]) tag[son[x][0]] ^= 1;
	if (son[x][1]) tag[son[x][1]] ^= 1;
	tag[x] = 0;
}

int merge(int x,int y) {
	if (!x || !y) return x | y;
	if (rnd[x] < rnd[y]) {
		spread(x);
		son[x][1] = merge(son[x][1], y);
		update(x); return x;
	}
	spread(y);
	son[y][0] = merge(x, son[y][0]);
	update(y); return y;
}

void split(int now,int k,int &x,int &y) {
	if (!now) {
		x = y = 0; return;
	}
	spread(now);
	if (siz[son[now][0]] < k) {
		x = now;
		split(son[x][1], k - siz[son[x][0]] - 1, son[x][1], y);
	}
	else y = now, split(son[y][0], k, x, son[y][0]);
	update(now);
}

//找出最小值的排名
int get_rk(int x) {
	int k = 1; //初始排名
	while (1) {
		spread(x);
		if (son[x][0] && mn[son[x][0]] == mn[x]) 
      		x = son[x][0]; //在左子树
		else if (son[x][1] && mn[son[x][1]] == mn[x]) 
        	k += siz[son[x][0]] + 1, x = son[x][1]; //在右子树
		else return k + siz[son[x][0]]; //在当前节点
	}
}

int v[N];
int main() {
	read(n);
	for (int i = 1;i <= n; i++) {
		read(a[i].num); a[i].pos = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1;i <= n; i++)
	v[a[i].pos] = i;
	for (int i = 1;i <= n; i++) 
		rt = merge(rt, build(v[i]));
	for (int i = 1;i <= n; i++) {
		int k = get_rk(rt);
		split(rt, k, x, y);
		split(x, k-1, x, z);
		tag[x] ^= 1;
		rt = merge(x, y);
		printf ("%d ", k + i - 1);
	}
	return 0;
}
/*
7
1 8 6 5 3 5 2

*/
