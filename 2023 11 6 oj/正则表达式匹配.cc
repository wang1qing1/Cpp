class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        s.insert(s.begin(), '1');
        p.insert(p.begin(), '1');
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 2; j <= m; j += 2)
            if (p[j] == '*') dp[0][j] = true;
            else break;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (p[j] == '*')
                    dp[i][j] = dp[i][j - 2] || (p[j - 1] == '.' || p[j - 1] == s[i]) && dp[i - 1][j];
                else
                    dp[i][j] = (p[j] == s[i] || p[j] == '.') && dp[i - 1][j - 1];
            }
        }
        return dp[n][m];

    }
};