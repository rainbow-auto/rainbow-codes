#include <bits/stdc++.h>
// #pragma GCC optimize(2)

using i64 = long long;
using f64 = long double;

#define fastread std::ios::sync_with_stdio (false); std::cin.tie(nullptr);

#define rep(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) <= (qaq); QWQ++)
#define per(QWQ, qwq, qaq) for (i64 QWQ = (qwq); (QWQ) >= (qaq); QWQ--)

#define RainbowAutomatonDebugFlag

#ifdef RainbowAutomatonDebugFlag
#define db(x) std::cerr << (#x) << " : " << x << "\n";
#define dbline() std::cerr << "\n"; 
#else
#define db(x) void (0);
#define dbline() void (0);
#endif

#define lookMem std::cerr << abs (&MemST - &MemED) / 1024.0 / 1024.0 << "MB defined\n";
#define lookTime std::cerr << (double) (clock () - TimeST) / CLOCKS_PER_SEC << "s used\n";
int TimeST;
bool MemST;

const int maxn = 10;

int n, m;
std::array<std::array<char,maxn>,maxn> ans,fans;

i64 stk[maxn], spos;
inline i64 calc (const std::string& s) {
    // std::cerr << s << ": ";
    spos = 0;
    int m=s.length()-1;
    int f=0;
    rep(i,0,m){
        if(s[i]=='+')continue;
        else if(s[i]=='*')f=1;
        else{
            int j=i;
            i64 num=0;
            while(j <= m && isdigit(s[j])){
                num=num*10+1;
                ++j;
            }
            if(f){stk[spos]*=num; f = 0; }
            else stk[++spos]=num;
            i = j - 1;
        }
    }
    i64 res = 0;
    rep(i,1,spos)res+=stk[i];
    // std::cerr << res << "\n";
    return res;
}
i64 ansnow=1e18;
void dfs (int x, int y, i64 val,int cnt) {
    // std::cerr << x << " " << y << "\n";
    if(val>=ansnow||cnt>3)return;
    if (x == n + 1) {
        i64 res = val;

        rep (i, 1, m) {
            std::string s;
            rep (j, 1, n) {
                s += ans[j][i];
            }
            res += calc (s);
        }

        if (res < ansnow) {
            fans=ans;
            ansnow=res;
        //     rep (i, 1, n) {
        //     rep (j, 1, m) {
        //         std::cerr << ans[i][j];
        //     }
        //     std::cerr << "\n";
        // }
        // std::cerr << res << "\n";
        }
        return;
    }    

    
    
    if(x!=1&&y!=1&&x!=n&&y!=m&&ans[x][y-1]=='1'&&ans[x-1][y]=='1'){
        ans[x][y]='*';
        dfs (x, y + 1,val,cnt);
        if(x!=2&&y!=2){
        ans[x][y]='+';
        dfs (x, y + 1,val,cnt+1); 
        }
    }
    else{
        ans[x][y]='1';
        std::string s;
    if (y == m) { 
        rep(j,1,m)s+=ans[x][j];
        dfs (x + 1, 1,val+calc(s),cnt); 
    }
    else{ dfs (x, y + 1,val,cnt); }
    }
}

inline void solve () {
    std::cin  >> n >> m;
    dfs (1, 1, 0,0);   

    // rep (i, 1, n) {
    //     rep (j, 1, m) {
    //         ans[i][j] = '1';
    //     }
    // }

    // rep (i, 2, n - 1) {
    //     rep (j, 2, m - 1) {
    //         if ((i & 1) == (j & 1)) { ans[i][j] = '*'; }
    //     }
    // }

    rep (i, 1, n) {
        rep (j, 1, m) {
            std::cout << fans[i][j];
        }
        std::cout << "\n";
    }
}

bool MemED;
int main () {
	fastread
	// lookMem	
	// TimeST = clock ();

	// int _; std::cin >> _;
    int _ = 1;
	while (_--) {
		solve ();
	}

    // std::string s; std::cin >> s;

	return 0;
}
