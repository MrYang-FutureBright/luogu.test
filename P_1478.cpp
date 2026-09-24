#include<iostream>
using namespace std;
int h[5005];
int w[5005];
int dp[5005][1005]={0};//数组要定义为全局数组，不然会栈溢出；
int main()
{
    int n,s,a,b;
    cin>>n>>s>>a>>b;
    
    int k=a+b;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i]>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(h[i]<=k&&j>=w[i])
            {
                dp[i][j]=dp[i-1][j-w[i]]+1>dp[i][j]?dp[i-1][j-w[i]]+1:dp[i][j];
            }
        }
    }
    cout<<dp[n][s];
    return 0;
}
