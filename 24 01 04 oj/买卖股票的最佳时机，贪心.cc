class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevmin=prices[0];
        int ret=0;
        for(auto e:prices)
        {
            prevmin=min(prevmin,e);
            ret=max(ret,e-prevmin);
        }
        return ret;
    }
};