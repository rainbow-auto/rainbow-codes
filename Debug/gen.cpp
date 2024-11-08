#include<iostream>
#include<random>
using namespace std;
const int maxn=3000;
const int maxp=10;
const int maxw=100000;
signed main(){

    mt19937 randseed(114514);
    
    srand (randseed());

    int n,k;
    n=rand()%maxn+1,k=rand()%maxn;

    cout << n << " " << k << endl; 
    for(int i=1;i<=n;++i){
        int p=rand()%maxp+1;

        cout << p << " ";
        for(int j=1;j<=p;++j){
            cout<<rand()%maxw+1<<' ';
        }
        cout<<'\n';
    }
    cout << endl;

    return 0;
}
