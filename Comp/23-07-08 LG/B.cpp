#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <stack>

using namespace std;

const int maxn = 1305;

int n;
int _a[maxn];
int belong[maxn];

stack <int> a;
stack <int> b;

vector <string> ans;

int main ()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> _a[i];		
		belong[_a[i]] = 1;
	}
	for (int i = n; i >= 1; i--)
	{
		a.push(_a[i]);
	}	
	
	for (int i = n; i >= 1; i--)
	{
		if (belong[i] == 1)
		{
			while (a.top() != i)
			{
				belong[a.top()] = 2;
				b.push(a.top());
				a.pop();
				ans.push_back("A B");
			}
			belong[a.top()] = 3;
			a.pop();
			ans.push_back("A C");
		}
		else if (belong[i] == 2)
		{
			while (b.top() != i)
			{
				belong[b.top()] = 1;
				a.push(b.top());
				b.pop();
				ans.push_back("B A");
			}
			belong[b.top()] = 3;
			b.pop();
			ans.push_back("B C");
		}
	}
	
	cout <<	ans.size () << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
	
	return 0;
}

