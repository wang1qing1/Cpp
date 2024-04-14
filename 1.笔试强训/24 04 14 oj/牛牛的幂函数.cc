class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param x double浮点型 
     * @param n int整型 
     * @return double浮点型
     */
    double dfs(double x,int n )
    {
        if(n==0)return 1;
        if(n==1)return x;
        if(n%2==0)return dfs(x,n/2)*dfs(x,n/2);
        else return dfs(x,(n-1)/2)*dfs(x,(n-1)/2)*x;
    }
    double myPow(double x, int n) {
        double ret=dfs(x,abs(n));
       return n>=0?ret:1.0/ret;
    }
};