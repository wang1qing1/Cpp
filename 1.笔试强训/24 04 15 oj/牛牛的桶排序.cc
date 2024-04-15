#include <cstddef>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型vector
     */
    vector<int> bucketSort(vector<int>& nums) {
        int Max=-0x3f3f3f3f;
        int Min=0x3f3f3f3f;
        for(auto e:nums)
        {
            Max=max(Max,e);
            Min=min(Min,e);
        }
        vector<int> arr(Max-Min+5,0);
        int N=abs(Min);
        for(auto e:nums)
        {
            arr[e+N]++;
        }
        vector<int> ret;
        for(int i=Min;i<=Max;i++)
        {
            while(arr[i+N]--)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};