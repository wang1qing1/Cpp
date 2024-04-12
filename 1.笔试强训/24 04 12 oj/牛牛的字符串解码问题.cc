class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
     //"3[a2[c]]"
    string decodeString(string s) {
        stack<int> st;
        stack<string> sta_str;
        int index=0;
        while(index<s.size())
        {
            if(s[index]>='0'&&s[index]<='9')
            {
                string num;
                while(index<s.size()&&s[index]!='[')
                {
                    num+=s[index];
                    index++;
                }
                int n=atoi(num.c_str());
                st.push(n);
            }
            else if(s[index]>='a'&&s[index]<='z')
            {
                string tmp;
                while(index<s.size()&&s[index]>='a'&&s[index]<='z')
                {
                    tmp+=s[index];
                    index++;
                }
                sta_str.push(tmp);
            }
            else if(s[index]=='[')index++;
            else if(s[index]==']')
            {
                int n=st.top();st.pop();
                string ss=sta_str.top();sta_str.pop();
                string tmp;
                for(int i=0;i<n;i++)tmp+=ss;
                if(!sta_str.empty())
                {
                    tmp=sta_str.top()+tmp;
                    sta_str.pop();
                }
                sta_str.push(tmp);
                index++;
            }
        }
        string ret;
        while(!sta_str.empty())
        {
            string tmp=sta_str.top();
             reverse(tmp.begin(),tmp.end());
            sta_str.pop();
            ret+=tmp;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};