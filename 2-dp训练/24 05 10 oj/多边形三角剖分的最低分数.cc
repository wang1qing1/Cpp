class Solution {
public:
    typedef vector<vector<int>> vvi;
    int dfs(vector<int>& values,int i,int j,vvi& dp)
    {
        int ans;
        if(dp[i][j]!=-1)return dp[i][j];
        else
        {
            if(i==j||j-i==1)ans=0;
            else if(j-i==2)ans=values[i]*values[j]*values[i+1];
            else 
            {
                int tmp=0x3f3f3f3f;
                for(int k=i+1;k<j;k++)
                {
                    tmp=min(tmp,dfs(values,i,k,dp)+dfs(values,k,j,dp)+values[i]*values[j]*values[k]);
                }
                ans=tmp;
            }
        }
        dp[i][j]=ans;
        return ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return dfs(values,0,n-1,dp);
     }
};