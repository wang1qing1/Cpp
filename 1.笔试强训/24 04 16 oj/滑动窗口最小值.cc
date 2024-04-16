#include <iomanip>
#include <list>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param k int整型 
     * @return int整型vector
     */
    int FinMin(list<int>& l)
    {
        int m=0x3f3f3f3f;
        for(auto e:l)
        {
            m=min(e,m);
        }
        return m;
    }
    vector<int> minSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;        
        list<int> hash(nums.begin(),nums.begin()+k);
        int i=0;
        while(i<nums.size()-k)
        {
            ret.push_back(FinMin(hash));
            hash.pop_front();   
            hash.push_back(nums[i+k]);
            i++;
        }
        ret.push_back(FinMin(hash));
        return ret;
    }
};