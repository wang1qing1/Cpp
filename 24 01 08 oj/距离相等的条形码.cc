class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n=barcodes.size();
        unordered_map<int,int> hash;
        int maxcount=0;
        int maxnum=0;
        for(auto e:barcodes)
        {
            hash[e]++;
            if(maxcount<hash[e])
            {
                maxcount=hash[e];
                maxnum=e;
            }
        }
        int index=0;
        vector<int> ret(n);
        //处理出现最多次数的数字
        for(int i=0;i<maxcount;i++)
        {
            ret[index]=maxnum;
            index+=2;
        }
        //删除maxnum
        hash.erase(maxnum);
        //处理剩余数字
        for(auto [a,b]:hash)
        {
            for(int i=0;i<b;i++)
            {
                if(index>=n)index=1;
                ret[index]=a;
                index+=2;
            }
        }
        return ret;
    }
};