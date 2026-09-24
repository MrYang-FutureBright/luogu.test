#include<iostream>
using namespace std;
int n,k;
int a[100001];
int ans=-1;
bool determain(int number)
{
    int count=0;
    for(int i=1;i<=n;i++)
    {
        count+=a[i]/number;
    }
    if(count>=k)
    {
        return true;
    }
    else return false;
}
int main()
{
    cin>>n>>k;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int key=sum/k;
    if(key<1)
    {
        cout<<0<<endl;
        return 0;
    }
    int left=1;
    int right=key;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(determain(mid))
        {
            ans=mid;
            left=mid+1;
        }
        else right=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}