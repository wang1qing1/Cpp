class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>> dp(n,vector<int>(n,0));
        int ret=0;
        int prev=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(i==j)
                {
                    if(nums[j]==0)prev=1;
                    else prev=-1;
                }
                else 
                {
                    if(nums[j]==0)prev=prev+1;
                    else prev=prev-1;
                }
                if(prev==0)ret=max(ret,i-j+1);
            }
        }
        return ret;
    }
};