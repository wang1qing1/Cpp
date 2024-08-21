class Solution {
public:
    vector<int> path;
    set<int> hash;
    vector<vector<int>> ret;
    void dfs(vector<int>& nums)
    {
        if(path.size()>nums.size())return;
        for(int i=0;i<nums.size();i++)
        {
            if(hash.find(nums[i])==hash.end())
            {
                path.push_back(nums[i]);
                hash.insert(nums[i]);
                if(path.size()==nums.size())
                {
                    ret.push_back(path);
                }
                dfs(nums);
                path.pop_back();
                hash.erase(nums[i]);
            }   
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return ret;
    }
};