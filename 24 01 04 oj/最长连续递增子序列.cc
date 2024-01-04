class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int left=0;
        int right=1;
        int ret=1;
        while(right<n)
        {
            if(nums[right-1]<nums[right])
            {
                right++;
            }
            else
            {
                ret=max(ret,right-left);
                left=right;
                right++;
            }
        }
        ret=max(ret,right-left);
        return ret;

    }
};