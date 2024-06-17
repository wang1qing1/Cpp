class Solution {
public:
    int bestTiming(vector<int>& prices) {
        int minprice=0x3f3f3f3f;
        int ret=0;
        for(auto e:prices)
        {
            minprice=min(e,minprice);
            ret=max(ret,e-minprice);
        }
        return ret;
        
    }
};