#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 600010;
int n, q, a[maxn], s[maxn], l, r, x;
char op;

struct Trie {
  int cnt, rt[maxn], ch[maxn * 33][2], val[maxn * 33];

  void insert(int o, int lst, int v) {
    for (int i = 4; i >= 0; i--) {
      val[o] = val[lst] + 1;  // 在原版本的基础上更新
    //   if ((v & (1 << i)) == 0) {
    //     if (!ch[o][0]) ch[o][0] = ++cnt;
    //     ch[o][1] = ch[lst][1];
    //     o = ch[o][0];
    //     lst = ch[lst][0];
    //   } else {
    //     if (!ch[o][1]) ch[o][1] = ++cnt;
    //     ch[o][0] = ch[lst][0];
    //     o = ch[o][1];
    //     lst = ch[lst][1];
    //   }

        bool num = (v & (1 << i));
        if (not ch[o][num]) { ch[o][num] = ++cnt; }
        ch[o][num ^ 1] = ch[lst][num ^ 1];
        o = ch[o][num];
        lst = ch[lst][num];
    }
    val[o] = val[lst] + 1;
    printf("%d\n",o);
  }

  int query(int o1, int o2, int v) {
    int ret = 0;
    for (int i = 4; i >= 0; i--) {
      // printf("%d %d %d\n",o1,o2,val[o1]-val[o2]);
      int t = ((v & (1 << i)) ? 1 : 0);
      if (val[ch[o1][!t]] - val[ch[o2][!t]])
        ret += (1 << i), o1 = ch[o1][!t],
                         o2 = ch[o2][!t];  // 尽量向不同的地方跳
      else
        o1 = ch[o1][t], o2 = ch[o2][t];
    }
    return ret;
  }
} st;

inline void display () {
    cout << "root: "; for (int i = 1; i <= n; i++) { cout << st.rt[i] << " "; } cout << endl;
    
    for (int i = 1; i <= st.cnt; i++) {
        cout << st.ch[i][0] << " " << st.ch[i][1] << " " << st.val[i] << endl;
    }
    
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", a + i), s[i] = s[i - 1] ^ a[i];
  for (int i = 1; i <= n; i++)
    st.rt[i] = ++st.cnt, st.insert(st.rt[i], st.rt[i - 1], s[i]);

  while (q--) {
    scanf(" %c", &op);
    if (op == 'A') {
      n++;
      scanf("%d", a + n);
      s[n] = s[n - 1] ^ a[n];
      st.rt[n] = ++st.cnt;
      st.insert(st.rt[n], st.rt[n - 1], s[n]);
    }
    if (op == 'Q') {
      scanf("%d%d%d", &l, &r, &x);
      l--;
      r--;
      cout << "l = " << l << " r = " << r << endl;

      if (l == 0)
        printf("%d\n", max(s[n] ^ x, st.query(st.rt[r], st.rt[0], s[n] ^ x)));
      else{
        printf("%d\n", st.query(st.rt[r], st.rt[l - 1], s[n] ^ x));
      }
    }
  }
  return 0;
}

/*
insert (2)
now = 1
now = 2
now = 3
now = 4
now = 5
5
insert (4)
now = 6
now = 7
now = 8
now = 9
now = 10
9
insert (0)
now = 11
now = 12
now = 13
now = 14
now = 15
16
insert (3)
now = 17
now = 18
now = 19
now = 20
now = 21
22
insert (5)
now = 23
now = 24
now = 25
now = 26
now = 27
22
insert (4)
now = 28
now = 29
now = 30
now = 31
now = 32
31
0
insert (0)
now = 33
now = 34
now = 35
now = 36
now = 37
38
0
4
*/

/*
insert (2)
now = 1
now = 2
now = 3
now = 4
now = 5
6
insert (4)
now = 7
now = 8
now = 9
now = 10
now = 11
12
insert (0)
now = 13
now = 14
now = 15
now = 16
now = 17
18
insert (3)
now = 19
now = 20
now = 21
now = 22
now = 23
24
insert (5)
now = 25
now = 26
now = 27
now = 28
now = 29
30
insert (4)
now = 31
now = 32
now = 33
now = 34
now = 35
36
4
insert (0)
now = 37
now = 38
now = 39
now = 40
now = 41
42
5
6
*/