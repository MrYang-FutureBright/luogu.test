#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
    while(b)
    {
        a=a%b;
        swap(a,b);
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<long long> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    } 
    vector<int> L(n+1,0);
    vector<int> R(n+1,n+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(gcd(a[i],a[j])>1)
            {
                L[i]=j;
                break;
            }
        }
        for(int j=i+1;j<=n;j++)
        {
            if(gcd(a[i],a[j])>1)
            {
                R[i]=j;
                break;
            }
        }
    }
    vector<vector<bool>> ok(n+1,vector<bool>(n+1,true));
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                if(L[k]<i&&R[k]>j)
                {
                    ok[i][j]=false;
                    break;
                }
            }
        }
    }
    vector<int> dp(n+1,-1);
    dp[0]=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            if(ok[j][i]&&dp[j-1]!=-1)
            {
                dp[i]=max(dp[i],dp[j-1]+1);
            }
        }
    }
    cout<<dp[n]<<endl;
}
