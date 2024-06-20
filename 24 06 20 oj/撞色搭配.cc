class Solution {
public:
    vector<int> sockCollocation(vector<int>& sockets) {
        int tmp=0;
        for(auto e:sockets)tmp^=e;
        int i=0;
        for(i=0;i<32;i++)
        {
            if((1<<i)&tmp)break;
        }
        int ret1=0;
        int ret2=0;
        for(auto e:sockets)
        {
            if(e&(1<<i))ret1^=e;
            else ret2^=e;
        }
        return {ret1,ret2};

    }
};