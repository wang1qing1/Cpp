class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int n = prices.size();
        int left = 0, right = 1;
        while (right < n)
        {
            if (prices[right] > prices[right - 1])right++;
            else
            {
                int profit = prices[right - 1] - prices[left];
                if (profit > 0)ret += profit;
                left = right;
                right++;
            }
        }
        if (prices[right - 1] - prices[left] > 0)ret += prices[right - 1] - prices[left];
        return ret;

    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i + 1] > prices[i])ret += (prices[i + 1] - prices[i]);
        }
        return ret;
    }
};