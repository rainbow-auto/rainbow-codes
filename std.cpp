#include <bits/stdc++.h>

using ll = long long;

const int N = 2e5 + 10;
const ll P = 1e9 + 7;
ll a[N], k1, k2;
int n, cnt = 2;
struct node{
	int ch[2], tag;
	ll sum;
} t[N*130];

void psd(int p){
	if(t[p].tag){
		if(t[p].ch[0]){
			t[t[p].ch[0]].sum = 0;
			t[t[p].ch[0]].tag = 1;
		}
		if(t[p].ch[1]){
			t[t[p].ch[1]].sum = 0;
			t[t[p].ch[1]].tag = 1;
		}
		t[p].tag = 0;
	}
}
void ins(int p, ll v, ll x){
	for(ll i = 62; i >= 0; -- i){
		psd(p);
		t[p].sum = (t[p].sum + x) % P;
		if(!t[p].ch[(v>>i)&1]){
			t[p].ch[(v>>i)&1] = ++ cnt;
		}
		p = t[p].ch[(v>>i)&1];
	}
	t[p].sum = (t[p].sum + x) % P;
}
ll qry(int p, ll v, ll w){
	ll ans = 0;
	for(ll i = 62; i >= 0; -- i){
		psd(p);
		if((w >> i) & 1){
			if(t[p].ch[!((v>>i)&1)]){
				p = t[p].ch[!((v>>i)&1)];
			} else {
				return ans;
			}
		} else {
			ans += t[t[p].ch[!((v>>i)&1)]].sum;
			if(t[p].ch[(v>>i)&1]){
				p = t[p].ch[(v>>i)&1];
			} else {
				return ans;
			}
		}
	}
	ans = (ans + t[p].sum) % P;
	return ans;
}
void fil(int p){
	t[p].sum = 0;
	t[p].tag = 1;
}

void solve(){
	// read(n, k1, k2);
	std::cin >> n >> k1 >> k2;
	for(int i = 1; i <= n; ++ i){
		std::cin >> a[i];
	}
	std::sort(a + 1, a + n + 1);
	ins(1, (1ll<<61), 1);
	ins(2, (1ll<<61), 1);
	for(int i = 2; i <= n; ++ i){
		ll sg = qry(1, a[i], k2);
		ll sf = qry(2, a[i], k1);
		if((a[i-1] ^ a[i]) < k1){
			std::cerr << "clear f\n";
			fil(1);
		}
		if((a[i-1] ^ a[i]) < k2){
			std::cerr << "clear g\n";
			fil(2);
		}
		std::cerr << "fnxt : " << sf << "\n";
		std::cerr << "gnxt : " << sg << "\n";

		ins(1, a[i-1], sf);
		ins(2, a[i-1], sg);
	}

	std::cerr << t[1].sum << " " << t[2].sum << "\n";

	int fa = 1, fb = 1;
	for(int i = 2; i <= n; ++ i){
		if((a[i-1] ^ a[i]) < k1){
			fa = 0;
		}
		if((a[i-1] ^ a[i]) < k2){
			fb = 0;
		}
	}
	std::cout << ((t[1].sum + t[2].sum - fa - fb + P) % P) << "\n";
}

int main () {
	solve ();
	return 0;
}
