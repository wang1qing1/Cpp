class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        // int kk=int(sqrt(k))+1;
        auto cmp=[](const vector<int>& v1,const vector<int>& v2)
        {
            return (v1[0]+v1[1])>(v2[0]+v2[1]);
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> min_pq;

        for(auto e1:nums1)
        {
            for(auto e2:nums2)
            {
                min_pq.push(vector<int>{e1,e2});
            }
        }
        vector<vector<int>> vvret;
        int tmp=min_pq.size();
        for(int i=0;i<min(k,tmp);i++)
        {
            vvret.push_back(min_pq.top());
            min_pq.pop();
        }  
        return vvret; 
    }
};