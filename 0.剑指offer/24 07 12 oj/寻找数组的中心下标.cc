class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prevSum(nums.size()+1);
        vector<int> LateSum(nums.size()+1);
        for(int i=0;i<nums.size();i++)
        {
            prevSum[i+1]=prevSum[i]+nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            LateSum[i]=LateSum[i+1]+nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(prevSum[i+1]==LateSum[i])return i;
        }
        return -1;
    }
};