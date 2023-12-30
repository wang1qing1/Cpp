class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int c=strs.size();
        unordered_map<string,vector<int>> hash;
        for(auto &str:strs)
        {
            hash[str]=vector<int>(2,0);
            for(auto e:str)
            {
                if(e=='0')hash[str][0]++;
                else hash[str][1]++;
            }   
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=1;i<=c;i++)
        {
            for(int j=m;j-hash[strs[i-1]][0]>=0;j--)
            {
                for(int k=n;k-hash[strs[i-1]][1]>=0;k--)
                {
                    dp[j][k]=max(dp[j][k],dp[j-hash[strs[i-1]][0]][k-hash[strs[i-1]][1]]+1);
                }
            }
        }
        return dp[m][n];
        
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int c=strs.size();
        unordered_map<string,vector<int>> hash;
        for(auto &str:strs)
        {
            hash[str]=vector<int>(2,0);
            for(auto e:str)
            {
                if(e=='0')hash[str][0]++;
                else hash[str][1]++;
            }   
        }
        vector<vector<vector<int>>> dp(c+1,vector<vector<int>>(m+1,vector<int>(n+1)));
        for(int i=1;i<=c;i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    dp[i][j][k]=dp[i-1][j][k];
                    if(j-hash[strs[i-1]][0]>=0&&k-hash[strs[i-1]][1]>=0)
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-hash[strs[i-1]][0]][k-hash[strs[i-1]][1]]+1);
                }
            }
        }
        return dp[c][m][n];
        
    }
};