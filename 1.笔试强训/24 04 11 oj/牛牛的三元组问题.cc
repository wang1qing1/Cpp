class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型vector<vector<>>
     */
    set<vector<int>> ret;
    vector<int> path;
    int sum=0;
    void dfs(vector<int>& nums,int begin)
    {
        if(0==sum&&path.size()==3)
        {
            auto tmp=path;
            sort(tmp.begin(),tmp.end());
            ret.insert(tmp);
        }
        if(begin>=nums.size())return;
        for(int i=begin;i<nums.size();i++)
        {
            sum+=nums[i];
            path.push_back(nums[i]);
            dfs(nums,i+1);
            path.pop_back();
            sum-=nums[i];
        }
    }
    vector<vector<int> > findTriplets(vector<int>& nums) {
            dfs(nums,0);
            return vector<vector<int>>(ret.begin(),ret.end());
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> findTriplets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ret;
        for(int i=0;i<nums.size();i++)
        {
            int target=0-nums[i];
            int left=0;
            int right=nums.size()-1;
            while(left<right)
            {
                if(left!=i&&right!=i&&nums[left]+nums[right]>target)
                {
                  right--;
                }
                else if(left!=i&&right!=i&&nums[left]+nums[right]<target)
                {
                  left++;
                }
                else 
                {
                    if(left!=i&&right!=i)
                    {
                        vector<int> tmp{nums[i],nums[left],nums[right]};
                        sort(tmp.begin(),tmp.end());
                        ret.insert(tmp);
                    }
                    left++;
                }
            }
            
        }
        return vector<vector<int>>(ret.begin(),ret.end());

    }
};