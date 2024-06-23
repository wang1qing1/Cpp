class Solution {
public:
    int divide(int a, int b) {
        long long tmpa = abs(a);
        long long tmpb = abs(b);
        long ret = 0;
        //�߽�
        if (a == INT_MIN && b == -1)
            return INT_MAX;
        if (a == INT_MIN && b == 1)
            return INT_MIN;
        while (tmpa >= tmpb)
        {
            int count = 0;
            //ÿ�ν�������һλ,��¼����count,�����ʱb���е�����2�η�
            while (tmpa >= (tmpb << count))count++;
            //�����,2^count
            ret += (1 << (count - 1));
            //����tmpa,Ҳ����tmpaʣ�µĲ��ּ�������tmpb�����2�η�
            tmpa -= (tmpb << (count - 1));
        }
        //����
        if ((a > 0 && b < 0) || (a < 0 && b>0))ret = -ret;
        return ret;
    }
};