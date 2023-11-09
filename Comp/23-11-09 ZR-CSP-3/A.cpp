#include <iostream>
#include <cstring>

using i64 = long long;

const int maxn = 25;

int n;
int a[maxn];

namespace Subtask1 {
    
    int siz;
    int pre[maxn];
    int nxt[maxn];

    inline void remove (int x) {
        nxt[pre[x]] = nxt[x];
        pre[nxt[x]] = pre[x];
        siz--;
    }

    int old_a[maxn];

    inline void solve () {

        memcpy (old_a, a, sizeof (a));

        int ans = 0x3f3f3f3f;

        for (int S = 0; S < (1 << n); S++) {
            for (int i = 1; i <= n; i++) {
                pre[i] = i - 1;
                nxt[i] = i + 1;
            }
            nxt[0] = 1;
            siz = n;

            for (int t = 1; t <= n; t++) {
                
                if (S & (1 << (t - 1))) { // 第一个
                    int now = nxt[0];

                    a[now] -= 2;
                    a[nxt[now]] --;
                    a[pre[now]] --;

                    if (siz > 1 and a[nxt[now]] <= 0) { remove (nxt[now]); }
                    if (a[now] <= 0) { remove (now); }
                
                } else { // 第二个
                    int now = nxt[nxt[0]];
                    if (siz < 2) { continue; }

                    a[now] -= 2;
                    a[nxt[now]] --;
                    a[pre[now]] --;

                    if (siz > 2 and a[nxt[now]] <= 0) { remove (nxt[now]); }
                    if (a[pre[now]] <= 0) { remove (pre[now]); }
                    if (a[now] <= 0) { remove (now); }

                }

                if (not siz) { ans = std::min (ans, t); break; }
            }
            memcpy (a, old_a, sizeof (old_a));
        }

        std::cout << ans << "\n";
    }
}

unsigned s1, s2, s3;
void Gen(){
    for(int i=1;i<=n;++i){
        s1^=s3;
        s3+=3055373123u;
        a[i]=(1<<((s1>>s2)&1));
        s2=(s2^s3)&31;
        s3=(s3>>s2)|((s3<<(31^s2))<<1);
    }
}

int main () {

    std::cin >> n >> s1 >> s2 >> s3;

    Gen ();
    
    Subtask1::solve ();

    return 0;
}