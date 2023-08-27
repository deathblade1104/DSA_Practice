class Solution {
public:
    int dp[2001][2001];
    unordered_map<int,int>mp;
    int n;
    bool helper(int curr,int k,vector<int>&arr){
        
        if(curr>=n-1)
            return true;
        
        if(dp[curr][k]!=-1)
            return dp[curr][k];
        
        bool ans = false;
        
        if(mp.count(arr[curr] + k))
            ans = helper(mp[arr[curr] + k],k,arr);
        
         if(ans)
            return dp[curr][k] = true;
        
        if(k>1 and mp.count(arr[curr] + k - 1))
            ans = ans | helper(mp[arr[curr] + k-1],k-1,arr);
        
        if(ans)
            return dp[curr][k] = true;
        
        if(mp.count(arr[curr] + k+1))
            ans = ans | helper(mp[arr[curr] + k+1],k+1,arr);
        
        if(ans)
            return dp[curr][k] = true;
            
        return dp[curr][k] = ans;
    }
    
    bool canCross(vector<int>& stones) {
        
        n = stones.size();
        
        if(stones[1]!=1)
            return false;
        
        for(int i=0;i<stones.size();i++)
            mp[stones[i]] = i;
        
        memset(dp,-1,sizeof dp);
        return helper(1,1,stones);
    }
};