class Solution {
public:
    vector<int> path;
    set<vector<int>> ret;
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
                vector<int> tmp=path;
                sort(tmp.begin(),tmp.end());
                ret.insert(tmp);
            }
            dfs(nums,i+1);
            path.pop_back();
            sum-=nums[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        tar=target;
        dfs(candidates,0);

        return vector<vector<int>>(ret.begin(),ret.end());
    }
};