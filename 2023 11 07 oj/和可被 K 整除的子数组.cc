class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        nums.insert(nums.begin(),0);
        unordered_map<int,int> hash;

        int dpj=nums[0];//dp[0]
        int dpi=0;
        int ret=0;
        for(int i=1;i<=n;i++)
        {
            hash[(dpj%k+k)%k]++;
            dpi=dpj+nums[i];
            ret+=hash[(dpi%k+k)%k];
            dpj=dpi;
        }
        return ret;
    }
};