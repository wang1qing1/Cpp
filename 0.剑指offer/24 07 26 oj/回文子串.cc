class Solution {
public:

    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        int ret=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(i==j)dp[i][j]=true;
                else if(i-j==1)
                {
                    if(s[i]==s[j])dp[i][j]=true;
                    else dp[i][j]=false;
                }
                else if(i-j>1)
                {
                     if(s[i]==s[j]&&dp[i-1][j+1])dp[i][j]=true;
                     else dp[i][j]=false;
                }
                if(dp[i][j])ret++;
            }
        }
        return ret;
    }
};