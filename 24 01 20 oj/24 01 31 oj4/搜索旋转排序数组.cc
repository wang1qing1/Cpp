class Solution {
public:
    int search(vector<int>& nums, int target) {
        int numright=nums.back();
        int left=0;
        int right=nums.size()-1;
        //旋转数组的二段性：
        //1.比最右边数字大
        //2.比最右边数字小
        while(left<right)
        {
            int mid=left+(right-left+1)/2;
            if(target<=numright)
            {
                if(nums[mid]>numright)left=mid+1;
                else if(nums[mid]<=numright &&target<nums[mid]) right=mid-1;
                else if(nums[mid]<=numright &&target>=nums[mid]) left=mid;
            }
            else
            {
                if(nums[mid]<=numright)right=mid-1;
                else if(nums[mid]>numright&& target<nums[mid])right=mid-1;
                else if(nums[mid]>numright&& target>=nums[mid])left=mid;
            }
        }
        return nums[left]==target?left:-1;
    }
};