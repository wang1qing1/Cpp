class Solution {
public:
    vector<int> path;
    unordered_map<int,int> hash;
    set<vector<int>> ret;
    void dfs(vector<int>& nums,unordered_map<int,int>& hashnums)
    {
        if(path.size()>nums.size())return;
        for(int i=0;i<nums.size();i++)
        {
            if(!((hash[nums[i]]>=hashnums[nums[i]])||(i>0&&nums[i]==nums[i-1])))
            {
                path.push_back(nums[i]);
                hash[nums[i]]++;
                if(path.size()==nums.size())
                {
                    ret.insert(path);
                }
                dfs(nums,hashnums);
                path.pop_back();
                hash[nums[i]]--; 
            }
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> hashnums;
        for(auto e:nums)hashnums[e]++;
        dfs(nums,hashnums);
        return vector<vector<int>>(ret.begin(),ret.end());
    }
};
//  1 1 2
//  1 1 2
//  1 1 2