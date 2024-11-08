#include <iostream>
#include <set>
#include <iterator>

using i64 = long long;

i64 w, h;
int q;

std::set <i64> x;
std::set <i64> y;

std::multiset <i64> dx;
std::multiset <i64> dy;

int main () {

    std::cin >> w >> h >> q;

    x.insert (0); x.insert (w);
    y.insert (0); y.insert (h);

    dx.insert (w); dy.insert (h);

    while (q--) {
        char ch; std::cin >> ch;

        if (ch == 'V') { 
            i64 pos; std::cin >> pos;
            auto it = x.lower_bound (pos);
            dx.erase (dx.find ((*it) - (*std::prev (it))));
            
            dx.insert ((*it) - pos);
            dx.insert (pos - (*std::prev (it)));

            x.insert (pos);
        }
        if (ch == 'H') { 
            i64 pos; std::cin >> pos;
            auto it = y.lower_bound (pos);
            dy.erase (dy.find ((*it) - (*std::prev (it))));
            
            dy.insert ((*it) - pos);
            dy.insert (pos - (*std::prev (it)));

            y.insert (pos);
        }

        i64 ans = (*dx.rbegin ()) * (*dy.rbegin ());
        std::cout << ans << "\n";
    }   
    
    return 0;
}