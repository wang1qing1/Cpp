class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */

    int longestUniqueSubarrayLength(vector<int>& nums) {
        int left=0;int right=0;
        set<int> hash;
     
        int ret=-1; 
        while(right<nums.size())
        {
            if(hash.find(nums[right])==hash.end())
            {
                hash.insert(nums[right++]);
                ret=max(ret,(int)hash.size());
            }
            else
            {
                hash.erase(nums[left++]);
            }
        }        
        ret=max(ret,(int)hash.size());
        return ret;
    }
};