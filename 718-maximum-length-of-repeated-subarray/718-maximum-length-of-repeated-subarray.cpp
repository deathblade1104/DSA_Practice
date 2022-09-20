class Solution {
public:
    
    int get_ans(int i,int j, int n, int m, vector<int>&s1, vector<int>&s2,vector<vector<int>>&dp,int &res)
    {
        if((i>=n) or (j>=m)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=0;
        
        if(s1[i]==s2[j])
        ans = 1 + get_ans(i+1,j+1,n,m,s1,s2,dp,res);
        
        int x = get_ans(i+1,j,n,m,s1,s2,dp,res);
        int y = get_ans(i,j+1,n,m,s1,s2,dp,res);
        
        res=max(res,ans);
      
        return dp[i][j]=ans;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size(), m = nums2.size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int res=-1;
        int x = get_ans(0,0,n,m,nums1,nums2,dp,res);
        return res;
    }
};