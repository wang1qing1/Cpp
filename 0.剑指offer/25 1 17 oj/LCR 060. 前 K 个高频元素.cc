class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> hashmap;
        for(auto e:nums)hashmap[e]++;

        auto comp=[](pair<int,int>& e1, pair<int,int>& e2){ return e1.second<e2.second;};
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>  max_pq;
        for(auto e:hashmap)
        {
            max_pq.push(e);
        }

        vector<int> ret;
        for(int i=0;i<k;i++)
        {
            ret.push_back(max_pq.top().first);
            max_pq.pop();
        }
        return ret;


    }
};