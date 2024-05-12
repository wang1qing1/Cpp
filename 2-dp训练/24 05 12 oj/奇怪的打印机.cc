class Solution {
public:
    typedef vector<vector<int>> vvi;
    int dfs(string& s,int l,int r,vvi& dp)
    {
        if(dp[l][r]!=-1)return dp[l][r];
        else
        {
            int tmp=0x3f3f3f3f;
            if(l==r)tmp=1;
            else if(r-l==1)tmp=s[l]==s[r]?1:2;
            else
            {
                for(int k=l;k<r;k++)
                {
                    tmp=min(dfs(s,l,k,dp)+dfs(s,k+1,r,dp),tmp);
                }
                if(s[l]==s[r])tmp=min(tmp,dfs(s,l,r-1,dp));
            }
            dp[l][r]=tmp;
        }
        return dp[l][r];
    }
    int strangePrinter(string s) {
        int n=s.size();
        //dp[l][r]:将s[l-r]刷成目标值的最少次数
        vvi dp(n,vector<int>(n,-1));
        return dfs(s,0,n-1,dp);
    }
};