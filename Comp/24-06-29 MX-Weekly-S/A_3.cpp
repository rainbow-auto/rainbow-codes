#include <iostream>
#include <set>
#include <vector>

const int maxn = 1000005;

int n;
int a[maxn];

int cnt[maxn];

struct Node {
    int val;
    
    friend bool operator < (Node a, Node b) { 
        if (cnt[a.val] != cnt[b.val]) { return cnt[a.val] > cnt[b.val]; }
        else { return a.val < b.val; }
    }
};

std::set <Node> rest;

int main () {

    std::cin >> n;

    for (int i = 1; i <= n; i++) { std::cin >> a[i]; cnt[a[i]] ++; }
    for (int i = 1; i <= n; i++) { rest.insert (Node { a[i] }); }

    if (rest.size () & 1) { std::cout << -1 << "\n"; return 0; }

    for (auto now : rest) { std::cout << now.val << " "; cnt[now.val]--; }

    rest.clear ();
    for (int i = 1; i <= n; i++) {
        if (cnt[a[i]]) { rest.insert (Node { a[i] }); }
    }

    while (rest.size ()) {
        std::vector<int> erase_list;
        
        for (auto now : rest) {
            std::cout << now.val << " ";
            cnt[now.val]--;
            if (not cnt[now.val]) { erase_list.push_back (now.val); }
        }

        for (auto now : erase_list) { rest.erase (Node{ now }); }
    }

    return 0;
}