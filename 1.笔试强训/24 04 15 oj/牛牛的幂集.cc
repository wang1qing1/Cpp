class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型vector<vector<>>
     */
    vector<int> path;
    set<vector<int>> ret;
    void dfs(vector<int>& nums,int begin)
    {
        ret.insert(path);
        if(begin>=nums.size())return;
        for(int i=begin;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            dfs(nums,i+1);
            path.pop_back();
        }
    } 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        dfs(nums,0);
        return vector<vector<int>>(ret.begin(),ret.end());
    }
};