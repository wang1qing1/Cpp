class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param input int整型vector 
     * @return int整型vector
     */
    vector<int> queueFromStack(vector<int>& input) {
        stack<int> stin;
        stack<int> stout;
        vector<int> ret;
        for(auto e:input)
        {
            if(e>0)
            {
               stin.push(e); 
            }
            else {
                if(stout.empty())
                {
                    while(!stin.empty())
                    {
                        stout.push(stin.top());
                        stin.pop();
                    }
                    ret.push_back(stout.top());
                    stout.pop();
                }
                else {
                    ret.push_back(stout.top());
                    stout.pop();
                }
            }
        }
        return ret;
    }
};