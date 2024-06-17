class Solution {
public:
    vector<int> countNumbers(int cnt) {
        int num=1;
        while(cnt--)num*=10;
        vector<int> ret;
        for(int i=1;i<num;i++)
        {
            ret.push_back(i);
        }
        return ret;
    }
};