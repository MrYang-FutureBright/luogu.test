#include<iostream>
#include<bits/stdc++.h>
using  namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    vector<int> arr(m);
    vector<int> brr(n);
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    for(int j=0;j<n;j++)
    {
        cin>>brr[j];
    }
    long long ans=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        int left=0;
        int right=m-1;
        int key=2e9;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(arr[mid]<brr[i])
            {
                key=min(key,abs(arr[mid]-brr[i]));
                left=mid+1;
            }
            else if(arr[mid]>brr[i])
            {
                key=min(key,abs(arr[mid]-brr[i]));
                right=mid-1;
            }
            else {
                key=0;
                break;
            }
        }
        ans+=key;
    }
    cout<<ans<<endl;
}