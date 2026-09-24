#include<iostream>
#include<cstdio>
using namespace std;
long long dp[25][25][25];
long long solve(long long a,long long b,long long c )
{
    if(a<=0||b<=0||c<=0)
    {
        return 1;
    }
    else if(a>20||b>20||c>20)
    {
        return solve(20,20,20);
    }
    if(dp[a][b][c]!=0)
    {
        return dp[a][b][c];
    }
    if(a<b&&b<c)
    {
        if(dp[a][b][c-1]==0)
        {
            dp[a][b][c-1]=solve(a,b,c-1);
        }
        if(dp[a][b-1][c-1]==0)
        {
            dp[a][b-1][c-1]=solve(a,b-1,c-1);
        }
        if(dp[a][b-1][c]==0)
        {
            dp[a][b-1][c]=solve(a,b-1,c);
        }
        dp[a][b][c]=dp[a][b][c-1]+dp[a][b-1][c-1]-dp[a][b-1][c];
    }
    else{
        if(dp[a-1][b][c]==0)
        {
            dp[a-1][b][c]=solve(a-1,b,c);
        }
        if(dp[a-1][b-1][c]==0)
        {
            dp[a-1][b-1][c]=solve(a-1,b-1,c);
        }
        if(dp[a-1][b][c-1]==0)
        {
            dp[a-1][b][c-1]=solve(a-1,b,c-1);
        }
        if(dp[a-1][b-1][c-1]==0)
        {
            dp[a-1][b-1][c-1]=solve(a-1,b-1,c-1);
        }
        dp[a][b][c]=dp[a-1][b][c]+dp[a-1][b-1][c]+dp[a-1][b][c-1]-dp[a-1][b-1][c-1];
    }
    return dp[a][b][c];
}
int main()
{
    long long  a,b,c;
    while(scanf("%lld%lld%lld", &a, &b, &c))
    {
        if((a==-1)&&(b==-1)&&(c==-1))
        {
            return 0;
        }
        printf("w(%lld, %lld, %lld) = ", a, b, c);
		printf("%lld\n", solve(a, b, c));
    }
    return 0;
}