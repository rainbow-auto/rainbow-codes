#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <sstream>
using namespace std;

vector<string> books;
vector<string> requests;
vector<int> lens;
vector<int> res;

bool cmp(int a,int b)
{
	return a < b;
}

int main()
{
	freopen ("librarian.in", "r", stdin);
	freopen ("librarian.out", "w", stdout);
    int n = 0;
	int q = 0;
	cin>>n>>q;
	
	for(int i = 0; i < n; i++)
	{
		string t;
		cin>>t;
		books.push_back(t);
	}
		
	for(int i = 0; i < q; i++)
	{
		string t;
		int ti;
		cin>>ti;
		cin>>t;
		lens.push_back(ti);
		requests.push_back(t);
	}
	//debug
//	cout<<"-----------------------------"<<endl;
	//debug
	for(int i = 0; i < q; i++)//i个请求(长度)，j本书 
	{
		vector<string> r;
		for(int j = 0; j < n; j++)
		{
			if(books[j].rfind(requests[i]) != string::npos)
			{
				if(books[j].rfind(requests[i]) == books[j].length() - lens[i])
				{
					r.push_back(books[j]);
				}
			}
		}
		if(r.empty())
		{
			res.push_back(-1);
		}
		else
		{
			vector <int> s;
			for(int k = 0; k < r.size(); k++)
			{
				int t;
				stringstream st;
				st<<r[k];
				st>>t;
				//debug
//				cout<<r[k]<<"   "<<t<<endl; 
				//debug
				s.push_back(t);
			}
			sort(s.begin(),s.end(),cmp);
			//debug
//			cout<<"-----------------"<<i<<"----------------"<<endl;
//			for(int x = 0; x < s.size(); x++)
//			{
//				cout<<s[x]<<"   ";
//			}
//			cout<<endl;
			//debug
			res.push_back(s[0]);
		}
	}
	//debug
//	cout<<"-----------------------------"<<endl;
	//debug
	for(int i = 0; i < q; i ++)
	{
		cout<<res[i]<<endl;
	}
	return 0;
} 
