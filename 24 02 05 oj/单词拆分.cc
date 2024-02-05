class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hashset(wordDict.begin(),wordDict.end());
        int n=s.size();
        s='1'+s;
        vector<bool> dp(n+1);
        string tmp=s.substr(1,1);
        dp[1]=hashset.find(tmp)!=hashset.end();
        for(int i=1;i<=n;i++)
        {
            bool flag=false;
            for(int j=1;j<=i;j++)
            {
                if(dp[j]&&hashset.find(s.substr(j+1,i-j))!=hashset.end()||hashset.find(s.substr(1,i))!=hashset.end())
                {
                    flag=true;
                    break;
                }
            }
            dp[i]=flag; 
        }
        return dp[n];
    }
};