class Solution {
public:
    vector<int> path;
    vector<vector<int>> ret;
    int sum=0;
    int tar;
    void dfs(vector<int>& nums,int index)
    {
        if(nums.size()>150||sum>tar)return ;
        for(int i=index;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            sum+=nums[i];
            if(sum==tar)
            {
                ret.push_back(path);
            }
            dfs(nums,i);
            path.pop_back();
            sum-=nums[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        tar=target;
        dfs(candidates,0);
        return ret;
    }
};