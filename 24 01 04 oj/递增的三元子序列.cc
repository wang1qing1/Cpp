class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> ret;
        ret.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>ret.back())
            {
                ret.push_back(nums[i]);
                if(ret.size()==3)return true;
            }
            else
            {
                for(int &e:ret)
                {
                    if(nums[i]<=e)
                    {
                        e=nums[i];
                        break;
                    }   
                }
            }
        }
        return false;
    }
};