class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型vector
     */
    vector<int> findSingleCowsII(vector<int>& nums) {
        map<int,int> hash;
        vector<int> ret;
        for(auto e:nums)hash[e]++;
        for(auto [a,b]:hash)
        {
            if(b==1)ret.push_back(a);
        }
        return ret;
    }
};