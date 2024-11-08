#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 10;
struct Sale{
	int time;
	int price;
	bool b;
};
int n;
int count = 0, si = 1;//count -尾 si -头 
Sale sales[MAXN];//1-n


int main()
{
	freopen("bus","r",stdin);
	freopen("bus","w",stdout);
	cin>>n;
	int way;
	int time;
	int price;
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		cin>>way>>price>>time;
		if(way == 0)
		{
			count ++;
			sales[count].price = price;
			sales[count].time = time;
			sales[count].b = true;
			res += price;	
			//cout<<"price is"<<price<<" res is"<<res<<endl;
		}
		if(way == 1)
		{
			bool flag = false;
			//找到适用于a[i]的优惠票 
			while(time - sales[si].time > 45 and si <= count)
			{
				//cout<<sales[si].time<<" , "<<sales[si].price<<"    "<<a[i].time <<" , "<<a[i].price<<endl;
				si++;	
			}
			int j;
			for(int j = si; j <= count; j++)
			{
				if(price <= sales[j].price and sales[j].b == true)
				{
					sales[j].b = false;
					flag = true;
					break; 
				}
			}
			if(flag == false) 
			{
				res+=price;
				//cout<<"---price is "<<price<<" res is "<<res<<endl;
				//cout<<si<<" "<<count<<" "<<flag<<endl;
				//cout<<"------------------------------"<<endl;
			}
		}	
	}
	cout<<res<<endl;
	
	fclose (stdin);
	fclose (stdout);
	
	return 0;
}
