class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int right=0;
        int left=0;
        int maxpos=0;
        int ret=0;
        while(left<=right)
        {
            if(maxpos>=n-1)return ret;
            for(int i=left;i<=right;i++)
            {
                maxpos=max(maxpos,nums[i]+i);
            }
            left=right+1;
            right=maxpos;
            ret++;           
        }
        return -1;
    }
};