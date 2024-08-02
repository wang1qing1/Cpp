class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ret;
        for(auto &str:tokens)
        {
            if(str=="+")
            {
                int num1=st.top();st.pop();
                int num2=st.top();st.pop();
                st.push(num1+num2);
            }
            else if(str=="-")
            {
                int num1=st.top();st.pop();
                int num2=st.top();st.pop();
                st.push(num2-num1);
            }
            else if(str=="*")
            {
                int num1=st.top();st.pop();
                int num2=st.top();st.pop();
                st.push(num1*num2);
            }
            else if(str=="/")
            {
                int num1=st.top();st.pop();
                int num2=st.top();st.pop();
                st.push(num2/num1);
            } 
            else
            {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};

