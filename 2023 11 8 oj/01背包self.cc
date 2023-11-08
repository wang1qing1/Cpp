#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long bagv;
    cin >> n >> bagv;
    vector<int> vv(n + 1); //体积
    vector<int> wv(n + 1); //价值
    for (int i = 1; i <= n; i++)
        cin >> vv[i] >> wv[i];

    vector<vector<long long>> dp(n + 1, vector<long long>(bagv+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= bagv; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - vv[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - vv[i]] + wv[i]);
        }
    }
    cout << dp[n][bagv] << endl;

    for (int i = 1; i <= bagv; i++) dp[0][i] = -1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= bagv; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - vv[i] >= 0 && dp[i - 1][j - vv[i]] != -1) 
                dp[i][j] = max(dp[i][j],dp[i - 1][j - vv[i]] + wv[i]);
        }
    }
    cout << (dp[n][bagv] == -1 ? 0 : dp[n][bagv]) << endl;
    return 0;
}