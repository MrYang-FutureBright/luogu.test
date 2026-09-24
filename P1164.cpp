#include<iostream>
#include<vector>
using namespace std;
int N,M;
vector<int>arr(101);
int dp[101][10001]={0};
int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(j==arr[i])
            {
                dp[i][j]=dp[i-1][j]+1;
            }
            else if(j>arr[i])
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i]];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[N][M];
}