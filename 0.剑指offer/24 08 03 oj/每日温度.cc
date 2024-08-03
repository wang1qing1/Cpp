class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;//只存储当前位置开始比自己大温度下标
        for(int i=n-1;i>=0;i--)
        {
            int tem=temperatures[i];
            while(!st.empty()&&tem>=temperatures[st.top()])st.pop();//小温度pop
            if(!st.empty())res[i]=st.top()-i;
            st.push(i);
        }
        return res;
    }
};

class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> ret(temperatures.size(),0);
        for(int i=0;i<temperatures.size()-1;i++)
        {
            for(int j=i+1;j<temperatures.size();j++)
            {
                if(temperatures[j]>temperatures[i])
                {
                    ret[i]=j-i;
                    break;
                }
            }
        }
        return ret;
    }
};


