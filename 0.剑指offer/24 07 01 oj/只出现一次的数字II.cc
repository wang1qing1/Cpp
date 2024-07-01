class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long ret=0;
        //遍历每一个元素的32个比特位
        //切记不能从低位 往 高位遍历,从遇到的第一位为1才开始算数值有效位
        for(int i=31;i>=0;i--)
        {
            int bits=0;
            for(auto e:nums)
            {
                if(e&(1<<i))bits++;
            } 
            bits%=3;
            //在遇到1之前ret一直是0
            ret=ret*2+bits;
        }
        return ret;
    }
};
