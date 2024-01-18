class Solution {
public:
    int getret(int num1 ,int num2,char op)
    {
        int ret=0;
        switch(op)
        {
            case '+':
                ret=num1+num2;
                break;
            case '-':
                ret=num1-num2;
                break;
            case '*':
                ret=num1*num2;
                break;
            case '/':
                ret=num1/num2;
                break;
        }
        return ret;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto &str:tokens)
        {
            if(str!="/"&&str!="+"&&str!="*"&&str!="-")//数字
            {
                st.push(atoi(str.c_str()));
            }
            else//运算符
            {
                int num1=st.top();st.pop();
                int num2=st.top();st.pop();
                int ret=getret(num2,num1,str[0]);
                cout<<ret<<" ";
                st.push(ret);
            }
        }
        return st.top();
        
    }
};