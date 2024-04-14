#include <string>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param num int整型 
     * @return bool布尔型
     */
    bool isSpecialNumber(int num) {
        int len=to_string(num).size();
        int begin=pow(10,len-1);
        for(int i=begin;i<=num;i++)
        {
            string n1=to_string(i);
            reverse(n1.begin(),n1.end());
            int n=atoi(n1.c_str());
            if(n+i==num)return true;
        }
        return false;
    }
};