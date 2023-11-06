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

const int maxn = 1000005;

int n;
int a[maxn];

int t[maxn], tsum;

int main ()
{
	int a_max = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a_max = max (a_max, a[i]);		
	}
	
	int cnt = 0;
	while (true)
	{
		for (int i =1; i <= n; i++)
		{
			t[a[i]] = 1;
		}
		
		int sum = 0;
		for (int i = 1; i <= a_max; i++)
		{
			sum += t[i];
		}
		if (sum <= 2) break;
		
		if (cnt % 2 == 0) // 操作1 
		{
			// 选最小值
			int min_a = 0x3f3f3f3f;
			int min_k = 0; 
			for (int i = 1; i <= n; i++)
			{
				if (min_a > a[i])
				{
					min_k = i;
					min_a = a[i];
				}
			}
			
			// 选次小值
			
			int c_min_a = 0x3f3f3f3f;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == min_a) continue;
			
				c_min_a = min (c_min_a, a[i]);
			} 
			
			a[min_k] = c_min_a;
						
			cnt ++;
		}
		
		else // 操作2 
		{
			// 选最小值
			int max_a = 0;
			int max_k = 0; 
			for (int i = 1; i <= n; i++)
			{
				if (max_a < a[i])
				{
					max_k = i;
					max_a = a[i];
				}
			}
			
			// 选次小值
			
			int c_max_a = 0x3f3f3f3f;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == max_a) continue;
			
				c_max_a = max (c_max_a, a[i]);
			} 
			
			a[max_k] = c_max_a;
						
			cnt ++;
		}
	}	
	
	for (int i =1; i <=n; i++)
	{
		
	}	

	return 0;
}

