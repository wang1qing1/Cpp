class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int indexg=0;
        int indexs=0;
        int ret=0;
        while(indexg<g.size()&&indexs<s.size())
        {
            if(g[indexg]<=s[indexs])
            {
                ret++;
                indexg++;
                indexs++;
            }
            else
            {
                indexs++;
            } 
        }
        return ret;
    }
};