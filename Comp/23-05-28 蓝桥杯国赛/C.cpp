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

string in;
stack<int> num;
stack<char> op; 

int compute (int a, int b, char op)
{
	if (op == '+')
	{
		return a + b;
	}
	if (op == '-')
	{
		return a - b;
	}
	if (op == '*')
	{
		return a * b;
	}
	if (op == '/')
	{
		return a / b;
	}
}

int main ()
{
	map <char, int> op_m;
	op_m['+'] = 1;
	op_m['-'] = 1;
	op_m['*'] = 2;
	op_m['/'] = 2;
	
	op_m['e'] = 0;
	
	getline(cin, in);
	
	for (int i = 0; i < in.size(); i++)
	{
		char now = in[i];
		if (now == ' ') continue;
		
		if (now >= '0' and now <= '9')
		{
			int num_now = now - '0';
			while (true)
			{
				i ++;
				if (i >= in.size())
				{
//					cout << "i > siz" << endl;
					break;
				}
				if (in[i] == '+' or in[i] == '-' or in[i] == '*' or in[i] == '/')
				{
//					cout << "in[i] not digit" << endl;
					break;
				}
				
				if (in[i] == ' ') continue;			
				
				num_now = num_now * 10 + in[i] - '0';
			}
//			cout << "get a num : " << num_now << endl; 
			num.push(num_now);
		}
		if (in[i] == '+' or in[i] == '-' or in[i] == '*' or in[i] == '/')
		{
			while (not op.empty() and op_m[in[i]] <= op_m[op.top()])
			{
				int t2 = num.top(); num.pop();
				int t1 = num.top(); num.pop();
//				cout << t1 << " " << op.top() << " " << t2 << endl; 
				int t = compute (t1, t2, op.top());
				num.push(t);
				op.pop();
			}
			op.push(in[i]);
		}
	}
	
	while (not op.empty())
	{
		int t2 = num.top(); num.pop();
		int t1 = num.top(); num.pop();
		int t = compute (t1, t2, op.top());
		num.push(t);
		op.pop();
	}
	
	cout << num.top() << endl;
		
	return 0;
}

