class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> setfind(isConnected.size(),-1);
        auto findroot=[&setfind](int x){
            while(setfind[x]>=0)x=setfind[x];
            return x;
        };
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(isConnected[i][j]==1)
                {
                    int rooti=findroot(i);
                    int rootj=findroot(j);
                    if(rooti!=rootj)
                    {
                        setfind[rooti]+=setfind[rootj];
                        setfind[rootj]=rooti;
                    }
                }
            }
        }
        int ret=0;
        for(auto e:setfind)if(e<0)ret++;
        return ret;
    }
};