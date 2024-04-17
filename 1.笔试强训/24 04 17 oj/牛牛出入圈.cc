#include <iterator>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param enter int整型vector 
     * @param leave int整型vector 
     * @return bool布尔型
     */
    bool validateCowCircle(vector<int>& enter, vector<int>& leave) {
        stack<int> st;
        int index=0;
        int ileave=0;
        st.push(enter[index++]);
        while(ileave<leave.size())
        {
            if(st.empty()||st.top()!=leave[ileave])
            {
                if(index==enter.size())return false;
                st.push(enter[index++]);
            }
            else {
                st.pop();
                ileave++;
            }
        }
        return st.empty();
    }
};