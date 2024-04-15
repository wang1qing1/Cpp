class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型vector
     */
    int findNextMax(vector<int>& nums,int begin)
    {
        for(int i=begin+1;i<nums.size();i++)
        {
            if(nums[i]>nums[begin])return nums[i];
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums) {
        vector<int> ret;        
        for(int i=0;i<nums.size();i++)
        {
            ret.push_back(findNextMax(nums,i));
        }
        return ret;
    }
};