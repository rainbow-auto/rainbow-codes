# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <string>
# include <map>
# include <cmath>
# include <cstring>
# define endl "\n"
using std::cin;
using std::cout;
template <typename T>
inline T min(T a, T b) {return a < b ? a : b;}
template <typename T>
inline T max(T a, T b) {return a > b ? a : b;}
using namespace std;

const int maxn = 8005;
int n, q;

struct Node{
	int id;
	int val;
	friend bool operator < (Node a, Node b)
	{
		if (a.val != b.val)
		{
			return a.val < b.val;
		}
		return a.id < b.id;
	}
};

Node a[maxn];

int t[maxn];                           

inline void update_t ()
{
	for (int i = 1; i <= n; i++)
	{
		t[a[i].id] = i;	
	}	
}				
  
int main ()
{
	freopen ("sort.in", "r", stdin);
	freopen ("sort.out", "w", stdout);

    cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].val;
		a[i].id = i; 
	}
	
	sort (a + 1, a + n + 1);
	update_t();
	
	for (int i = 1; i <= q; i++)
	{
		int op;
		cin >> op;
		if (op == 1)	
		{
			int x, v;
			cin >> x >> v;
			a[t[x]].val = v;
			for (int j = 2; j <= n; j++)
			{
				if (a[j] < a[j - 1])
				{
					swap (a[j], a[j - 1]); 
				}
			}
			for (int j = n; j >= 2; j--)
			{
				if (a[j] < a[j - 1])
				{
					swap (a[j], a[j - 1]);
				}
			}
			update_t ();
		} 
		else if (op == 2)
		{
			int x;
			cin >> x;
			cout << t[x] << endl;
		}
	}
	
	return 0;
}

