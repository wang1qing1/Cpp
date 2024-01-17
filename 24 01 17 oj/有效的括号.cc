class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch:s)
        {
            if(ch=='('||ch=='['||ch=='{')st.push(ch);
            else 
            {
                if(st.empty())return false;
                char c=st.top();
                st.pop();
                if(!(ch==')'&&c=='('||ch==']'&&c=='['||ch=='}'&&c=='{'))
                {
                    return false;
                }
            }
        }    
        return st.empty();
    }
};