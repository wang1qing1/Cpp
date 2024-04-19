#include <functional>
#include <queue>
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
    vector<int> findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        vector<int> ret;
        for(int i=0;i<nums.size();i++)
        {
            if(q.size()<k)
            {
                q.push(nums[i]);
            }
            else {
                if(nums[i]>=q.top())
                {
                    q.pop();
                    q.push(nums[i]);
                }
            }
            if(i>=k-1)ret.push_back(q.top());
        }
        return ret;

    }
};