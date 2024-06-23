class Solution {
public:
    int divide(int a, int b) {
        long long tmpa = abs(a);
        long long tmpb = abs(b);
        long ret = 0;
        //边界
        if (a == INT_MIN && b == -1)
            return INT_MAX;
        if (a == INT_MIN && b == 1)
            return INT_MIN;
        while (tmpa >= tmpb)
        {
            int count = 0;
            //每次进行左移一位,记录次数count,代表此时b具有的最大的2次方
            while (tmpa >= (tmpb << count))count++;
            //结果集,2^count
            ret += (1 << (count - 1));
            //更新tmpa,也就是tmpa剩下的部分继续计算tmpb的最大2次方
            tmpa -= (tmpb << (count - 1));
        }
        //符号
        if ((a > 0 && b < 0) || (a < 0 && b>0))ret = -ret;
        return ret;
    }
};