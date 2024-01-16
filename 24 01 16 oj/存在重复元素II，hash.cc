class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++)
        {
            if(hash.find(nums[i])!=hash.end()&&abs(i-hash[nums[i]])<=k)//找到相同数字
            {
               return true;
            }
            hash[nums[i]]=i;
        }
        return false;
    }
};