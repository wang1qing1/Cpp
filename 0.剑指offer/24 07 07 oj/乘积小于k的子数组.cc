class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int sum=1;
        int ret=0;
        //求以nums[right]结尾的乘积小于K的最长子数组
        //这个子数字内部的子数字都是乘小于K的共有(right-left+1);
        for(right=0;right<nums.size();right++)
        {
            sum*=nums[right];
            while(left<=right&&sum>=k)
            {
                sum/=nums[left++];
            }
            ret+=(right-left+1);
        }
        return ret;
    }
};
//这个子数字内部的子数字都是乘小于K的共有(right-left+1).
//left不断向右边移动，直到left>right,
//所以得到4+3+2+1
//比如 5 2 4 1 整个数组的乘积都是小于100的
// 5 2 4 1
// 2 4 1 , 5 2 4
// 4 1 ,5 2,2 4,
// 5, 2, 4, 1
//