#include <functional>
#include <future>
#include <queue>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param weights int整型vector 
     * @return double浮点型vector
     */
    vector<double> calculateMedians(vector<int>& weights) {
        priority_queue<int,vector<int>,less<>> rightS;//大堆
        priority_queue<int,vector<int>,greater<>> leftB;//小堆
        vector<double> ret;
        for(auto e:weights)
        {
            if(leftB.empty())
            {
                leftB.push(e);
                ret.push_back(e);
            }
            else 
            {
                if(leftB.top()<=e)
                {
                    if(leftB.size()==rightS.size()) 
                    {
                        leftB.push(e);
                        ret.push_back(leftB.top());
                    }
                    else
                    {
                        leftB.push(e);
                        rightS.push(leftB.top());
                        leftB.pop();
                        ret.push_back((leftB.top()+rightS.top())*0.5);
                    }
                }
                else {
                    if(leftB.size()==rightS.size())
                    {
                        rightS.push(e);
                        leftB.push(rightS.top());
                        rightS.pop();
                        ret.push_back(leftB.top());
                    }
                    else
                    {
                        rightS.push(e);
                        ret.push_back((leftB.top()+rightS.top())/2.0);
                    }
                }
            }
        }
        return ret;
    }
};