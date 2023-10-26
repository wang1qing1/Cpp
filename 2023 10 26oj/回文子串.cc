class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        int ret=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j)
                    dp[i][j]=true;
                else
                {
                    if(s[i]!=s[j]) dp[i][j]=false;
                    else 
                    {
                        if(j-i>1)
                            dp[i][j]=dp[i+1][j-1];
                        else if(j-i==1)
                            dp[i][j]=true;
                    }
                }
                if(dp[i][j])
                    ret++;
            }
        }
        return ret;
    }
};