#include <iostream>
using namespace std;

const int maxn = 505;

// a[0] 用来存储长度 

int A[maxn]; 
int B[maxn];

void add (int a[], int b[], int c[])
{
	int x = 0;	
	for (int i = 1; i <= max (a[0], b[0]); i ++)
	{
		c[++ c[0]] = a[i] + b[i] + x;
		x = c[i] / 10;
		c[i] %= 10;
	}
	if (x > 0)
	{
		c[++ c[0]] = x;
	}
	return;	
}

int main ()
{
	string a, b;
	cin >> a >> b;
	
	for (int i = a.size() - 1; i >= 0; i--)
	{
		A[++A[0]] = a[i] - '0';
	}
	for (int i = b.size() - 1; i >= 0; i--)
	{
		B[++B[0]] = b[i] - '0';
	}
	
	int c[maxn];
	c[0] = 0;
	
	add (A, B, c);
	for (int i = c[0]; i >= 1; i--)
	{
		cout << c[i];
	}
	cout << endl;
	
	return 0;	
} 
