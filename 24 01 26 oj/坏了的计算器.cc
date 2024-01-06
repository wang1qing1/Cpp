class Solution {
public:
    int brokenCalc(int begin, int end) {//5 8
        int ret=0;
        while(begin!=end)
        {
            if(end<begin)//b==5 e==4
            {
                ret+=(begin-end); 
                end=begin;
            }
            else if(begin<end)
            {
                if(end%2==1)
                {
                    end++;
                    ret++;
                }
                else
                {
                    end/=2;
                    ret++;
                }
            }
        }
        return ret;
    }
};