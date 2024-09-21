class Solution {
public:
    vector<vector<string>> arr;
    vector<string> path;
    bool isOK(string& str)
    {
        int left=0;int right=str.size()-1;
        while (left < right)
        {
            if (str[left] != str[right])
            {
                return false;
            }
            left++, right--;
        }
        return true;
    }
    void dfs(string& s,int index,const vector<vector<bool>>& dp)
    {
       if(index>=s.size())
       {
            arr.push_back(path);
            return;
       }
       for(int i=index;i<s.size();i++)
       {
            string tmpstr=string(s.begin()+index,s.begin()+i+1);
            if(dp[i][index])
            {
                path.push_back(tmpstr);
                dfs(s,i+1,dp);
                path.pop_back();
            }
       }
    }
    vector<vector<string>> partition(string& s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(i==j)dp[i][j]=true;
                else
                {
                    if(i-j<=2)
                    {
                        dp[i][j]=s[i]==s[j];
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j+1]&&s[i]==s[j];
                    }
                }
            }
        }
        dfs(s,0,dp);
        return arr;
    }
};