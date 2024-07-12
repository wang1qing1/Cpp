class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> prevSum(nums.size()+1);
        unordered_map<int,int> map;
        map[0]=-1;
        int ret=0;
        for(int i=0;i<nums.size();i++)
        {
            //遇到nums[i]==0转换成-1，方便后续的前缀和
            if(nums[i]==0)nums[i]=-1;
            prevSum[i+1]=nums[i]+prevSum[i];
            //第一次出现
            //前缀和中，相同的值之间[i,j)的数之和为0
            if(map.find(prevSum[i+1])==map.end())
            {
                map[prevSum[i+1]]=i;
            }
            else
            {
                ret=max(ret,i-map[prevSum[i+1]]);
            }
        }
        return ret;
    }
};