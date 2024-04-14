class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型vector
     */
    vector<int> findValley(vector<int>& nums) {
        vector<int> tmpnum;
        tmpnum.push_back(0x3f3f3f3f);
        for(auto e:nums)tmpnum.push_back(e);
        tmpnum.push_back(0x3f3f3ff3);
        multiset<int> ret;
        for(int i=1;i<tmpnum.size();i++)
        {
            if(tmpnum[i]<tmpnum[i+1]&&tmpnum[i]<tmpnum[i-1])
            {
                ret.insert(tmpnum[i]);
            }
        }
        return vector<int>(ret.begin(),ret.end());
        
    }
};