class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;   
        if(nums.size()==0)return ret;
        int left=0;
        int right=1;
        while(right<nums.size())
        {
            if(nums[right]==nums[right-1]+1)
            {
                right++;
            }
            else
            { 
                string tmp;
                if(left!=right-1) tmp=to_string(nums[left])+"->"+to_string(nums[right-1]);
                else tmp=to_string(nums[left]);
                 ret.push_back(tmp);
                left=right;
                right++;
            }
        }
        string tmp;
        if(left!=right-1) tmp=to_string(nums[left])+"->"+to_string(nums[right-1]);
        else tmp=to_string(nums[left]);
        ret.push_back(tmp);
        return  ret;
    }
};