class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param intervals int整型vector<vector<>> 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > mergeAnimalRanges(vector<vector<int> >& intervals) {
        //  前缀排序
        sort(intervals.begin(),intervals.end(),[&](vector<int>&e1,vector<int>&e2){
            return e1[0]<e2[0];
        });
        vector<vector<int>> ret;
        for(auto &e:intervals)
        {
            if(ret.empty())ret.push_back(e);
            else
            {
                //[1,10]+[5,15]->[1,15]
                //[1,10]+[2,8]->[1,10]
                //[1,10]+[15,20]->[1,10],[15,20]
                if(e[0]<=ret[ret.size()-1][1]&&e[1]>ret[ret.size()-1][1])
                {
                    ret[ret.size()-1][1]=e[1];
                }
                else if(e[0]>ret[ret.size()-1][1])
                {
                    ret.push_back(e);
                }
            }            
        }
        return ret;

    }
};