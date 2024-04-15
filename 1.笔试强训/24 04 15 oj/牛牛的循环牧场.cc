#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return bool布尔型
     */
    bool isOk(set<int>& hash,vector<int>& nums)
    {
        int flag1=true;int flag2=true;
        for(auto e:hash)
        {
            if(nums[e]>0)flag2=false;
            if(nums[e]<0)flag1=false;
        }
        return flag1||flag2;
    }   
    bool checkCircularArray(vector<int>& nums) {
        set<int> hash;
        int i=0;
        while(i<nums.size())
        {
            //检查是否有出现重复的结点
            if(hash.find(i)==hash.end())
            {
                hash.insert(i);
                i=(i+nums[i])%nums.size();
            }
            else
            {
                //出现重复的结点，说明已经出现闭环，检查经过的路径是否符号同一
                if(isOk(hash,nums))return true;
                else return false;
            } 
        }
        return false;
    }
};