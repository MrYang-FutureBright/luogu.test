#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<int> dp(amount,amount+1);
        dp[0]=0;
        for(int i=coins[0];i<=amount;i++)
        {
            for(int j=0;i<n;j++)
            {
                if(i<coins[j]) break;
                else dp[i]=min(dp[i-coins[j]]+1,dp[i]);
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
    }
};
