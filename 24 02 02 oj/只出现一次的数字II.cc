class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long ret=0;
        //记录每一位为1的个数,如果刚好是三的倍数，那这个就不是出现一次的1.
        //否则他也是出现一次的数字的1
        for(int i=0;i<32;i++)
        {
            int count=0;
            for(auto e:nums)
            {
                if(e&(1<<i))count++;
            }
            if(count%3==1) ret+=pow(2,i);
        }
        return ret;
    }
};