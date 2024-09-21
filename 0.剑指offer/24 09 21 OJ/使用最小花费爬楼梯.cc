class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n=cost.size();
        int dp0,dp1,dp2;
        dp0=cost[0];
        dp1=cost[1];
        for(int i=2;i<n;i++)
        {
            dp2=min(dp0,dp1)+cost[i];
            dp0=dp1;
            dp1=dp2;
        }
        return dp2;
    }
};