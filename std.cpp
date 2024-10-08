#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cctype>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <iostream>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define db std::cerr
using namespace std;
typedef long long ll;
typedef pair <int, int> Pii;
const int INF=0x3f3f3f3f;
const int cp=998244353;
inline int mod(int x){if(x>=cp) x-=cp;if(x<0) x+=cp;return x;}
inline void plust(int &x, int y){x=mod(x+y);return ;}
inline void minut(int &x, int y){x=mod(x-y);return ;}
inline int read(){
	char ch=getchar();int x=0, f=1;
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(int x){
    if(x<0) putchar('-'), x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline int ksm(int a, int b=cp-2){
	int ret=1;
	for(; b; b>>=1, a=1ll*a*a%cp)
		if(b&1) ret=1ll*ret*a%cp;
	return ret;
}
const int N=2e5+1;
const int M=1e6+1;
namespace Trie{
	const int B1=511;
	int X, lv1[512], lv2[512][512];
	void clr(){memset(lv1, 0, sizeof(lv1));memset(lv2, 0, sizeof(lv2));}
	void insert(int x){
		for(int y=0; y<=B1; ++y) 
			lv1[y]+=((y^(x>>9))<(X>>9)),
			lv2[x>>9][y]+=((y^(x&B1))<=(X&B1));
	}
	int query(int x){return lv1[x>>9]+lv2[(x^X)>>9][x&B1];}
}
int n, m, B2, a[N], b[M];ll ans[M], sum[2][M];
struct qry{int l, r, bl, id;}q[M];
struct node{int l, r, id, op;};vector <node> scd[N];//op=+-1 为移动询问 op=2/3 为前缀询问
bool Mcmp(qry a, qry b){return a.bl^b.bl?a.l<b.l:((a.bl&1)?a.r>b.r:a.r<b.r);}
signed main(){
	n=read(), Trie :: X=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	m=read();B2=n/sqrt(m)+1;
	for(int i=1; i<=m; ++i) 
		q[i].l=read(), q[i].r=read(), q[i].id=i, q[i].bl=q[i].l/B2;
	sort(q+1, q+m+1, Mcmp);
	int L=1, R=0;
	for(int i=1; i<=n; ++i)
		sum[0][i]=sum[0][i-1]+Trie :: query(a[i]), Trie :: insert(a[i]), sum[1][i]=sum[1][i-1]+Trie :: query(a[i]);

    for (int i = 1; i <= n; i++) {
        db << sum[0][i] - sum[0][i - 1] << " \n"[i == n];
    }

    for (int i = 1; i <= n; i++) {
        db << sum[1][i] - sum[1][i - 1] << " \n"[i == n];
    }

	Trie ::clr();
	for(int i=1; i<=m; ++i){
		int x=q[i].l, y=q[i].r;b[q[i].id]=i;
		// printf("[%d %d] to %d[%d %d]\n", L, R, ip, x, y);
		if(x<L) {
            ans[i]-=sum[1][L-1]-sum[1][x-1], scd[R].pb((node){x, L-1, i, 1}),
            L=x;//[L, R] to [x, R] (x<l) add every i in [x, L) for [1, R]-[1, i]
        }
		if(R<y) {
            ans[i]+=sum[0][y]-sum[0][R], scd[L-1].pb((node){R+1, y, i, -1}),
            R=y;//[L, R] to [L, y] (R<y) add every i in (R, y] for [1, i)-[1, L)
        }
		if(x>L) { 
            ans[i]+=sum[1][x-1]-sum[1][L-1], scd[R].pb((node){L, x-1, i, -1}),
            L=x;//[l, R] to [x, R] (x<l) sub every i in [L, x) for [1, R]-[1, i]
        }
        if(R>y) {
            ans[i]-=sum[0][R]-sum[0][y], scd[L-1].pb((node){y+1, R, i, 1}),
            R=y;//[L, R] to [L, y] (R>y) sub every i in (y, R] for [1, i)-[1, L)
        }
	}
	for(int i=1; i<=n; ++i){
		Trie :: insert(a[i]);
        db << "ins " << a[i] << "\n";
		for(auto [l, r, ip, op]:scd[i])
			for(int j=l; j<=r; ++j) {
                ans[ip]+=op*Trie :: query(a[j]);
                db << "qry " << a[j] << " " << Trie::query(a[j]) << "\n";
            }
	}
	for(int i=1; i<=m; ++i) ans[i]+=ans[i-1];
	for(int i=1; i<=m; ++i) printf("%lld\n", ans[b[i]]);
	return 0;
}
/*
ins 11
ins 4
ins 5
ins 1
ins 4
ins 1
ins 9
ins 1
ins 9
ins 8
qry 11 4
qry 4 3
qry 5 6
qry 1 4
qry 4 3
qry 1 4
qry 9 4
ins 10
*/