class Solution {
public:
    vector<int> maxAltitude(vector<int>& heights, int limit) {
        queue<int> q;
        list<int> maxlist;
        vector<int> ret;
        if(heights.size()<limit)return ret;
        for(auto e:heights)
        {
            q.push(e);
            while(!maxlist.empty()&&maxlist.back()<e)maxlist.pop_back();
            maxlist.push_back(e);
            if(q.size()==limit) 
            {
                ret.push_back(maxlist.front());
                int front=q.front();
                q.pop();
                if(front==maxlist.front()) maxlist.pop_front();
            }  
        }
        return ret;
    }
};