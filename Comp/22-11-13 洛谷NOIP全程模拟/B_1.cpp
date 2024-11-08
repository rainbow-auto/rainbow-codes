#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100005;

int n, k;
string s;
string ans;

bool used[maxn];

int main ()
{
	cin >> n >> k;
	cin >> s;
	
	int total = 0;	
	memset (used, 0, sizeof (used));
	for (int i = 0; i < s.size(); i++)
	{
		int now = i;
		int min_char = 0xff;
		int min_char_pos = 0;
		int cnt = 0;
		while (cnt <= k)
		{
			if (not used[now]) cnt ++;
			now ++;
			if (s[now] < min_char)
			{
				min_char = s[now];
				min_char_pos = now;
			}
		}	
		if (total > k)
		{
			ans += s[i];
		}
		else
		{
			ans += min_char;
			used[min_char_pos] = true;
			total += min_char_pos - i;
		}
	}
	
	cout << ans << endl; 
	return 0;
}

