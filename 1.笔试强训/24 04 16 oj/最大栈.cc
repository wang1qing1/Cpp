class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param operations string字符串vector 
     * @param values int整型vector 
     * @return int整型vector
     */
    vector<int> processStackOperations(vector<string>& op, vector<int>& values) {
        vector<int> ret;
        stack<int> st;
        stack<int> maxst;
        for(int i=0;i<op.size();i++)
        {
            if(op[i]=="push")
            {
                st.push(values[i]);
                if(maxst.empty()||values[i]>maxst.top())maxst.push(values[i]);
                else maxst.push(maxst.top());
            }
            else if(op[i]=="getMax"){
                ret.push_back(maxst.top());
            }
            else if(op[i]=="pop")
            {
                st.pop();maxst.pop();
            }
            else {
                ret.push_back(st.top());
            }
        }
        return ret;
    }
};