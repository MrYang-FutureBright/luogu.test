#include<iostream>
using namespace std;
long long N,M;
long long arr[1000000];
bool check(int k)
{
    long long sum=0;
    for(int i=0;i<N;i++)
    {
        if(k>=arr[i]) continue;
        else sum+=(arr[i]-k);
    }
    if(sum>=M) return true;
    else return false;
}
int main()
{
    cin>>N>>M;
    long long max=0;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    long long ans=-1;
    long long left=0;
    long long right=max;
    while(left<=right)
    {
        long long mid=(left+right)/2;
        if(check(mid))
        {
            left=mid+1;
            ans=mid;
        }
        else right=mid-1;
    }
    cout<<ans<<endl;
}