class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numTickets int整型 
     * @param visitorTimes int整型vector 
     * @return int整型vector
     */
    vector<int> ticketQueue(int numTickets, vector<int>& vis) {
        multimap<int,int> v;
        for(int i=0;i<vis.size();i++)
        {
            v.insert({vis[i],i});
        }
        vector<int> ret;    
        for(auto [a,b]:v)ret.push_back(b+1);
        return ret;

    }
};