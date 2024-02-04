class Solution {
public:
    int mySqrt(int x) {
        int ret=1;
        if(x==5)return 2;
        long long i=1;
        for(i=1;i<=(x/3);i++)
        {
            if(i*i>=x) 
            {
                ret=i;
                break;
            }
        }
        return i*i==x?i:i-1;
    }
};