//一、暴力解法(会超时)
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     long long count=0;
//     vector<int> p(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>p[i];
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             if(i<j&&p[i]>p[j])
//             {
//                 count++;
//             }
//         }
//     }
//     cout<<count<<endl;
// }
//二、归并排序解法
#include<iostream>
#include<bits/stdc++.h>
const int N=5e5+5;
using namespace std;
long long a[N];
long long cnt[N];
long long sum=0;
void merge_sort(int l,int r)
{
    if(l==r)
    {
        return;
    }
    int mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int i=l;
    int j=mid+1;
    int k=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])
        {
            cnt[k++]=a[i++];
        }
        else
        {
            cnt[k++]=a[j++];
            sum+=mid-i+1;
        }
    }
    while(i<=mid)
    {
        cnt[k++]=a[i++];
    }
    while(j<=r)
    {
        cnt[k++]=a[j++];
    }
    for(int x=l;x<=r;x++)
    {
        a[x]=cnt[x];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    merge_sort(1,n);
    cout<<sum<<endl;
    return 0;
}