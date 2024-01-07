class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int Max=0x3f3f3f3f;
        int sum=0;
        int x1=Max; int y1=Max;
        int y2=Max; int x2=Max;
        for(auto e:nums)
        {
            sum+=e;//求和
            if(e%3==1)
            {
                if(e<=x1)
                {
                    x2=x1;
                    x1=e;
                }
                else if(e>x1&&e<x2) x2=e;
            }
            else if(e%3==2)
            {
                if(e<=y1)
                {
                    y2=y1;
                    y1=e;
                }
                else if(e>y1&&e<y2) y2=e;
            }
        }
        if(sum%3==0)return sum;
        else if(sum%3==1) return max(sum-x1,sum-y1-y2);
        else return max(sum-y1,sum-x1-x2);
        
    }
};