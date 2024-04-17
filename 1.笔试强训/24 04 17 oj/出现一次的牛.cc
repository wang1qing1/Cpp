class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int findSingleCow(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto e:nums)hash[e]++;
        int ret=-1;
        for(auto &[a,b]:hash) if(b==1)ret=a;
        return ret;
    }
};