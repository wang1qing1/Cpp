class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> ret;
        ret.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>ret.back())
            {
                ret.push_back(nums[i]);
            }
            else
            {
                int left=0;int right=ret.size()-1;
                while(left<right)
                {
                    int mid=left+(right-left)/2;
                    if(ret[mid]>=nums[i]) right=mid;
                    else left=mid+1;
                }
                ret[left]=nums[i];
            }
        }
        return ret.size();
    }
};