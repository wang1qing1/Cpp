class Solution {
public
    vectorint path;
    vectorvectorint ret;
    int n;
    void dfs(unordered_setint& chack,vectorint& nums)
    {
        if(path.size()==nums.size())
        {
            ret.push_back(path);
            return ;
        }
        for(int i=0;inums.size();i++)
        {
            if(chack.find(nums[i])==chack.end())
            {
                chack.insert(nums[i]);
                path.push_back(nums[i]);
                dfs(chack,nums);
                path.pop_back();
                chack.erase(nums[i]);
            }
        }
    }
    vectorvectorint permute(vectorint& nums) {
        n=nums.size();
        unordered_setint chack;
        dfs(chack,nums);
        return ret;
    }
};
};