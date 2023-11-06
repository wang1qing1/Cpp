class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),0);
        vector<int> ldp(n+2,0);
        vector<int> rdp(n+2,0);
        for(int i=1;i<=n;i++)
        {
            ldp[i]=ldp[i-1]+nums[i];
        }
        for(int i=n;i>=1;i--)
        {
            rdp[i]=rdp[i+1]+nums[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(ldp[i]==rdp[i]) return i-1;
        }
        return -1;
    }
};