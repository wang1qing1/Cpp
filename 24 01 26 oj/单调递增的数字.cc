
//模拟
class Solution {
public:
    int IsIncreaNum(string& str)
    {
        for(int i=0;i<str.size()-1;i++)
        {
            if(str[i]>str[i+1]) return i;//不是单调递增的数字
        }
        return -1;//是个单调递增的数字
    }
    int monotoneIncreasingDigits(int n) {
        string num=to_string(n);
        int ret=IsIncreaNum(num);
        while(ret!=-1)
        {
            num[ret]--;
            for(int i=ret+1;i<num.size();i++)num[i]='9';
            ret=IsIncreaNum(num);
        }
        return atoi(num.c_str());

    }
};

//贪心
class Solution {
public:

    int monotoneIncreasingDigits(int n) {
        string num=to_string(n);
        int i=0;
        //找到第一个开始递减的位置
        while(i+1<num.size()&&num[i]<=num[i+1])i++;
        if(i+1==num.size())return n;

        //找到前面和他全部相等的数字
        while(i-1>=0&&num[i]==num[i-1])i--;

        num[i]--;
        for(i=i+1;i<num.size();i++)
        {
            num[i]='9';
        }
        return stoi(num);

    }
};