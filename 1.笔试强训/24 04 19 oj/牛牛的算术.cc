class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param x int整型 
     * @return int整型
     */
    int sqrt(int x) {
        int ret=0;
        for(int i=0;i<=(x/2)+1;i++)
        {
            if(i*i==x)
            {
                ret=i;break;
            }
            else if(i*i>x)
            {
                ret=i-1;
                break;
            }
        }
        return ret;

    }
};