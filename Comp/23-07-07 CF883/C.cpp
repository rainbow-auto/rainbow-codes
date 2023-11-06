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

#define int long long

int T;
int n, m, h;

struct P{
	vector<int> times;
	int id;
	int score, penalty;
	
	void solve ()
	{
		sort (times.begin(), times.end());
		penalty = 0;
		score = 0;
		
		int time_sum = 0;
		while (score + 1 <= m)
		{
//			cout << "score: " << score << " pennalty: " << penalty << endl;
			if (time_sum + times[score + 1] > h) break;
			score++;
			time_sum += times[score]; 
			penalty += time_sum;
		}
	}	
	
	friend bool operator < (P a, P b)
	{
		if (a.score == b.score) 
		{
			if (a.penalty != b.penalty) return a.penalty < b.penalty;
			else return a.id < b.id;
		}
		else return a.score > b.score;
	}
	
};

vector <P> t;

signed main ()
{
	cin >> T;
	
	while (T--)
	{
		t.clear();
		
		cin >> n >> m >> h;
		
		for (int i = 1; i <= n; i++)
		{
			P now;
			now.times.push_back(0);
			for (int j = 1; j <= m; j++)
			{
				int curr_t;
				cin >> curr_t;
				now.times.push_back (curr_t);
			}
			now.solve();
			now.id = i;
			t.push_back(now);
			
//			cout << "now : id = " << now.id << " score = " << now.score << " penalty = " << now.penalty << endl;
//			cout << "t : id = " << t[i - 1].id << " score = " << t[i - 1].score << " penalty = " << now.penalty << endl;
			
		}
		
		sort (t.begin(), t.end());
		
//		cout << "case " << T << "--------------"<< endl;
		for (int i = 0; i < t.size(); i++)
		{
//			cout << t[i].id << " " << t[i].score << " " << t[i].penalty << endl; 
			
			if (t[i].id == 1)
			{
//				cout << "Answer------" << endl;
				cout << i + 1 << endl;
//				cout << "------------" << endl;
			}
		}	
		
//		cout << "--------------------" << endl;
	}

	return 0;
}

