class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    int countDays(int n) {
        int d1 = 1;
        int d2 = 2;
        int d3;
        for (int i = 3; i <= n; i++)
        {
            d3 = d1 + d2;
            d1 = d2;
            d2 = d3 % (1000000007);
        }
        if (n == 0)return 1;
        if (n == 2)return 2;
        if (n == 1)return 1;
        return d3;
    }
};