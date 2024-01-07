class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[&](auto e1,auto e2)
        {
            return e1[0]==e2[0]?e1[1]>e2[1]:e1[0]<e2[0];
        });
        vector<int> ret;
        ret.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++)
        {
            if(envelopes[i][1]>ret.back())
            {
                ret.push_back(envelopes[i][1]);
            }
            else
            {
                int left=0;
                int right=ret.size()-1;
                while(left<right)
                {
                    int mid=left+(right-left)/2;
                    if(ret[mid]>=envelopes[i][1]) right=mid; 
                    else if(ret[mid]<envelopes[i][1])left=mid+1;
                }
                ret[right]=envelopes[i][1];
            }
        }
        return ret.size();
    }
};