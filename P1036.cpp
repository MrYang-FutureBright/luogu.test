#include<iostream>
#include<vector>
using namespace std;
int n,k;
int count=0;
vector<int>a(25);
bool issu(int m)
{
    if(m==1) return false;
    for(int i=2;i*i<=m;i++)
    {
        if(m%i==0)
        {
            return false;
        }
    }
    return true;
}
void solve(int hpick,int sum,int index)
{
    if(hpick==k)
    {
        if(issu(sum))
        {
            ++count;
        }
        return;
    }
    for(int i=index;i<=n-k+hpick+1;i++)
    {
        solve(hpick+1,sum+a[i],i+1);//注意一定是i+1不是index+1才能保证不回头选不重复；
    }
    return;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    solve(0,0,1);
    cout<<count<<endl;
}
