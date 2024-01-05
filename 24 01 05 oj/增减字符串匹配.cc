
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int left=0;
        int right=s.size();
        vector<int> ret;
        for(auto e:s)
        {
            if(e=='I')
            {   
                ret.push_back(left++);
            }
            else
            {
                ret.push_back(right--);
            }
        }
        ret.push_back(right);
        return ret;
    }
};