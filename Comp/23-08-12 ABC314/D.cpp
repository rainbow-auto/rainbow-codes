#include <iostream>

using namespace std;

const int maxn = 500005;

int n, q; string s;
// struct BIT {
//     int tr[maxn];
//     inline int lowbit(int x) { return x & (-x); }
//     inline void _add(int x, int pos) { for (int i = pos; i <= n; i += lowbit(i)) { tr[i] += x; } }
//     inline void add (int x, int l, int r) { _add(l, x); _add(r + 1, -x); }
//     inline void query (int pos) { int res = 0; for (int i = pos; i; i -= lowbit(i)) { res += x } return res; }
// } lower_case, upper_case;

int lower_case[maxn], upper_case[maxn];
int lower_case_tag, upper_case_tag;

int main () {

    cin >> n;
    cin >> s; s = " " + s;
    cin >> q;

    int last = 0;

    while (q--) {
        int op, x; char c;
        cin >> op >> x >> c;
        switch (op) {
            case 1:
                last = 1;
                s[x] = c;
                // int od_lc = lower_case.query(x);
                // int od_uc = upper_case.query(x);
                // lower_case.add(-od_lc, x, x);
                // upper_case.add(-od_uc, x, x);
                lower_case[x] -= lower_case_tag;
                upper_case[x] -= upper_case_tag;
                break;   
            case 2:
                last = 2;
                lower_case_tag ++;
                break;
            case 3:
                upper_case_tag ++;
                break;
        }
    }

    for (int i = 1; i < s.size(); i++) {
        int lc = lower_case[i] + lower_case_tag;
        int uc = upper_case[i] + upper_case_tag;

        if (lc == 0 and rc == 0) { cout <<  }

        // if (isupper(s[i])) {
        //     if (lc) { cout << char(s[i] + 32); }
        //     else { cout << char(s[i]); }
        // } else {
        //     if (uc) { cout << char(s[i] - 32); }
        //     else { cout << char(s[i]); }
        }
    }

    return 0;
}