class Solution {
public:
    int inventoryManagement(vector<int>& stock) {
        int ret=stock[0];
        int count=0;
        for(auto e:stock)
        {
            if(ret==e)count++;
            else
            {
                count--;
                if(count==0)
                {
                    ret=e;
                    count=1;
                }
            }
        }
        return ret;
    }
};