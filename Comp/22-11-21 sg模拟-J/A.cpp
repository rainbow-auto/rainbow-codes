#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

string a;
string b;
string s;

queue <int> q; 
int table[26][26];

int main ()
{
	freopen ("vige.in", "r", stdin);
	freopen ("vige.out", "w", stdout);
	
	cin >> s >> b;
	for (int i = 0; i < 26; i++)
	{
		q.push(i);
	}
	
	for (int i = 0; i < 26; i++)
	{
		int x = q.front ();
		q.push(x);
		q.pop();
		for (int j = 26 - 1; j >= 0; j --)
		{
			table[i][j] = q.front();
			q.push(table[i][j]);
			q.pop();
		}
	}
	
	int k = 0;
	for (int i = 0; i < b.size(); i++)
	{
		if (k >= s.size())
		{
			k = 0;
		}
		
		if (b[i] < 'a') // ด๓ะด 
		{
			if (s[k] < 'a') // ด๓ะด
			{
				cout << char ((table[b[i] - 'A'][s[k] - 'A']) + 'A');	
			} 
			else
			{
				cout << char ((table[b[i] - 'A'][s[k] - 'a']) + 'A');
			}
		}
		else
		{
			if (s[k] < 'a')
			{
				cout << char ((table[b[i] - 'a'][s[k] - 'A']) + 'a');
			}
			else
			{	
				cout << char ((table[b[i] - 'a'][s[k] - 'a']) + 'a');
			}
		}
		
		k ++;
	} 
	
	return 0;
}

