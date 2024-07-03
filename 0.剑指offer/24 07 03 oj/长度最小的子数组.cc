class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int left=0;
        int right=0;
        int ret=0x3f3f3f3f;
        //滑动窗口
        //窗口右边扩展
        while(right<nums.size())
        {
            sum+=nums[right];
            right++;
            //如果sum>=tar，记录结果ret，并且收缩窗口
            while(sum>=target)
            {
                ret=min(ret,right-left);
                sum-=nums[left];
                left++;
            }
        }
        return ret==0x3f3f3f3f?0:ret;
    }
};