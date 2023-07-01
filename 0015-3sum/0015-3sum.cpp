class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
         for(int i=0;i<nums.size();i++)
        {
            int j=i+1,k=nums.size()-1;            
            
            while(j<k)
            {                
                if(nums[i] + nums[j] + nums[k] <0){
                    j++;
                    
//                     int l = nums[j];
                    
//                     while(j<nums.size() and j<k and nums[j]==l)
//                         j++;
                }
                
                else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                    
                    // int  r= nums[k];
                    //  while(k>=0 and k>j and nums[k]==r)
                    //     k--;
                }
                
                else
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    
                    int l = nums[j], r= nums[k];
                    
                    while(j<nums.size() and j<k and nums[j]==l)
                        j++;
                    
                    while(k>=0 and k>j and nums[k]==r)
                        k--;
                    
                }
            }
            
            int x = nums[i];
            while(i+1<nums.size() and nums[i+1]==x)
                i++;
        }
        
        return ans;
    }
};