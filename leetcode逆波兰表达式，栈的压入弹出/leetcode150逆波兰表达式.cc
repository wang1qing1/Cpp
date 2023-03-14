class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string>::iterator it=tokens.begin();
        stack<int> st;
        while(it!=tokens.end())
        {
            if(*it=="+"||*it=="-"||*it=="*"||*it=="/")
            {
                int right=st.top();
                st.pop();
                int left=st.top();
                st.pop();
                switch((*it)[0])
                {
                    case '+':
                    st.push(right+left);
                        break;
                    case '-':
                    st.push(left-right);
                        break;
                    case '*':
                    st.push(left*right);
                        break;
                    case '/':
                    st.push(left/right);
                        break;
                }
            }
            else
            {
                int num=atol((*it).c_str());
                st.push(num);
            }
            it++;
        }
        return st.top();
    }
};
//JZ31 栈的压入、弹出序列 
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;
        vector<int>::iterator itpop=popV.begin(); 
        vector<int>::iterator itpush=pushV.begin();
        while(itpush!=pushV.end())
        {
            st.push(*itpush);
            itpush++;
            while(!st.empty()&&st.top()==*itpop)
            {
                st.pop();
                itpop++;
            }
        }
        return st.empty();
    }
};