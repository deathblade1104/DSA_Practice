class Solution {
public:
    int get_sum(int n)
    {
        return (n * (n+1))/2;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        int ans=0,count=0;
        
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
                count++;
            
            else
            {
                ans+=get_sum(count);
                count=0;
            }
        }
        
        ans+=get_sum(count);
        return ans;
    }
};