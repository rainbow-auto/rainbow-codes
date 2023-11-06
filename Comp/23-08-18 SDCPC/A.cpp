#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

const int maxn = 105;

int n, k;

struct Task {
    int a, b;
    friend bool operator < (Task x, Task y) {
        return x.a < y.a;
    }
};
vector<Task> tasks;

signed main () {
    
    int T; cin >> T;
    while (T--) {
        tasks.clear();

        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            int a, b; cin >> a >> b;
            tasks.push_back (Task{a, b});
        }

        sort (tasks.begin(), tasks.end());

        int now = 0, last = 0; // 当前库存 | 上一天是那一天
        for (auto task : tasks) { 
            now += (task.a - last) * k; last = task.a;
            now -= task.b;
            if (now < 0) { cout << "No" << endl; goto end; }
        }

        cout << "Yes" << endl;

        end: continue;
    }

    return 0;
}