#include<iostream>
using namespace std;
using ll = long long;
int main()
{
    ll n,k,x;
    cin>>n>>k>>x;
    ll len=(n-1)*x+1;
    if(len>k)
    {
        cout<<-1<<endl;
        return 0;
    }
    else if(k>len+2*x-2)
    {
        cout<<-1<<endl;
        return 0;
    }
    else
    {
        ll start=x;
        ll end=n*x;
        ll m=k-len;
        while(m>0&&start>1)
        {
            start--;
            m--;
        }
        while(m>0&&end<(n+1)*x)
        {
            end++;
            m--;
        }
        cout<<start<<' '<<end<<endl;
    }
}