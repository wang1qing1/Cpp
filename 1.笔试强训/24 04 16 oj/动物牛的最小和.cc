class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param k int整型 
     * @return int整型
     */
    int findMinSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0;int right=nums.size()-1;
        int ret=0x3f3f3f3f;
        while(left<right)
        {
            if(nums[left]+nums[right]>k)
            {
                ret=min(ret,nums[left]+nums[right]);
                right--;
            }
            else {
                left++;
            }
        }

        return ret==0x3f3f3f3f?-1:ret;
    }
};