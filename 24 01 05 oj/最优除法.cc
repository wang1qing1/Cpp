class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(nums.size()==1)return to_string(nums[0]);
        if(nums.size()==2)return to_string(nums[0])+"/"+to_string(nums[1]);
        string ret;
        for(int i=0;i<nums.size();i++)
        {
            ret+=to_string(nums[i]);
            ret+='/';
            if(i==0)ret+='(';
        }
         ret[ret.size()-1]=')';
         return ret;
    }
};