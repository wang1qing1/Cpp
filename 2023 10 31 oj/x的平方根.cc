class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        else if(x>=1&&x<=3) return 1;
        else if(x>=4&&x<=8) return 2;
        
        int a=x/3;
        int left=3;int right=a;
        while(left<right)
        {
            long long mid=(long long)left+(right-left+1)/2;
            if(mid*mid>x)
                right=mid-1;
            else 
                left=mid;
        }
        return left;
    }
};