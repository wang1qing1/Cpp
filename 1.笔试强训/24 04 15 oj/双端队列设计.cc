class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param operations int整型vector<vector<>> 
     * @param k int整型 
     * @return int整型vector
     */
    vector<int> performOperations(vector<vector<int> >& op, int k) {
       deque<int> deq;
       vector<int> ret;
       for(auto& v:op)
       {
            if(v[0]==1) 
            {
                if(deq.size()<k)
                {
                    deq.push_front(v[1]);
                    ret.push_back(0);
                }
                else ret.push_back(-1);       
            }
            else if(v[0]==2) 
            {
                if(deq.size()<k)
                {
                    deq.push_back(v[1]);
                    ret.push_back(0);
                }
                else ret.push_back(-1);
            }
            else if(v[0]==3)  
            {
                if(!deq.empty())
                {
                    deq.pop_front();
                    ret.push_back(0);
                }
                else ret.push_back(-1);
            }
            else if(v[0]==4)  
            {
                if(!deq.empty())
                {
                    deq.pop_back();
                    ret.push_back(0);
                }
                else ret.push_back(-1);
            }
            else if(v[0]==5) 
            {
                if(!deq.empty())
                {
                    ret.push_back(deq.front());
                }
                else ret.push_back(-1);
            } 
            else if(v[0]==6) 
            {
                if(!deq.empty())
                {
                   ret.push_back(deq.back());
                }
                else ret.push_back(-1); 
            }
       }
       return ret;
    }
};