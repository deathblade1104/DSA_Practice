class Solution {
public:
    int dp[10001];
    int solve(int amt,int&n,vector<int>&coins)
    {
        if(amt==0)
            return 0;
        
        if(dp[amt]!=-1)
        return dp[amt];
        
        int temp = 100000;
        for(int i=n-1;i>=0;i--)
        {
            if(coins[i]<=amt)
            temp = min(temp, 1 + solve(amt-coins[i],n,coins));
        }
        
        return dp[amt]=temp;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        sort(coins.begin(),coins.end());        
        memset(dp,-1,10001*sizeof(int));
        int ans=solve(amount,n,coins);
        
        if(ans >= 100000)
            return -1;
        else
            return ans;
    }
};