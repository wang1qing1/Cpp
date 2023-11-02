class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // if(nums.size()==1) return 0;
        int left=0;
        int right=nums.size()-1;
        while(left<right)
        {
            int mid= left+(right-left+1)/2;
            if(nums[mid]<nums[mid-1]) right=mid-1;
            else if(nums[mid]>nums[mid-1]) left=mid;
        }
        return left;
    }

};