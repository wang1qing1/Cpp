class Solution {
public:
    vector<int> path;
    set<vector<int>> hash;
    void dfs(vector<int>& nums,int index)
    {
        if(index>=nums.size())return ;
        for(int i=index;i<nums.size();i++)
        {
            
            path.push_back(nums[i]);
            hash.insert(path);
            dfs(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,0);
        hash.insert(vector<int>());
        return vector<vector<int>>(hash.begin(),hash.end());
    }
};