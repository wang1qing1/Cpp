class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        
        vector<int> f(n);
        vector<int> g(n);
        
        f[0]=-prices[0]-fee;

        for(int i=1;i<n;i++)
        {
            f[i]=max(f[i-1],g[i-1]-prices[i]-fee);
            g[i]=max(g[i-1],f[i-1]+prices[i]);
        }
        
        return g[n-1];

    }
};