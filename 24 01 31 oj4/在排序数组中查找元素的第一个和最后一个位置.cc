class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())return {-1,-1};
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>=target) right=mid;
            else left=mid+1;
        }
        int l=nums[left]==target?left:-1;
        left=0;
        right=nums.size()-1;
        while(left<right)
        {
            int mid=left+(right-left+1)/2;
            if(nums[mid]>target) right=mid-1;
            else left=mid;
        }
        return l==-1?vector{-1,-1}:vector{l,left};
    }
};