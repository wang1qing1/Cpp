class Solution {
public:
    bool wordBreak(string& s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> dp(n+1,true);
        s="_"+s;
        unordered_set<string> hash;
        for(auto &e:wordDict) hash.insert(e);
         
        for(int i=1;i<=n;i++)
        {
            bool flag=false;
            for(int j=1;j<=i;j++)
            {
                if(dp[j-1]&&hash.find(string(s.begin()+j,s.begin()+i+1))!=hash.end())
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