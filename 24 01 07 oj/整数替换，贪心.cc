class Solution {
public:
    int integerReplacement(long long n) {
        int ret=0;
        while(n!=1)
        {
            if(n==3)return ret+=2;
            else if(n%2==0)//偶数
            {   
                n/=2;   
            }
            else if(n%2==1)
            {
                if(n%4==1)n-=1;
                else n+=1; 
            }
            ret++;
        }
        return ret;
    }
};