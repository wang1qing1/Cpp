class Solution {
public:
    bool checkDynasty(vector<int>& places) {
        int count0=0;
        int tmp=0;
        sort(places.begin(),places.end());
        for(int i=0;i<places.size()-1;i++)
        {
            if(places[i]==0)count0++;
            else
            {
                //相同朝代不算连续
                if(places[i]==places[i+1])return false;
                tmp+=(places[i+1]-places[i]-1);
            }
        }
        return count0>=tmp;
    }
};