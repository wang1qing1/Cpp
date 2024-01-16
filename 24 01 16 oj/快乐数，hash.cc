class Solution {
public:
    int HappyNum(int num)
    {
        int ret=0;
        while(num){
            ret+=(num%10)*(num%10);
            num/=10;
        }
        return ret;
    }


    bool isHappy(int n) {
        set<int> hash;//记录出现的数字，再次出现就是环
        hash.insert(n);
        while(n!=1)
        {
            n=HappyNum(n);
            if(hash.find(n)!=hash.end())
            {
                return false;
            }
            hash.insert(n);
        }
        return true;
    }
};
//2  4  16  37  9+49=58  25+64=89  64+91=155 1+25+25=51 25+1=26  4+36=40 16 