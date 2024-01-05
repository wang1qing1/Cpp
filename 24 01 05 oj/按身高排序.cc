class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> index;
        for(int i=0;i<names.size();i++)index.push_back(i);

        sort(index.begin(),index.end(),[&](int i,int j){
            return heights[i]>heights[j];
        });

        vector<string> ret;
        for(int i=0;i<index.size();i++)
        {
            ret.push_back(names[index[i]]);
        }
        return ret;
    }
};
//map————排序+捆绑
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> hash;
        for(int i=0;i<names.size();i++)
        {
            hash.insert({heights[i],names[i]});
        }
        vector<string> ret;
        for( auto rit=hash.rbegin();rit!=hash.rend();rit++) ret.push_back(rit->second);
        return ret;
    }
};
//对下标排序
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> index;
        for(int i=0;i<names.size();i++)index.push_back(i);

        sort(index.begin(),index.end(),[&](int i,int j){
            return heights[i]>heights[j];
        });

        vector<string> ret;
        for(int i=0;i<index.size();i++)
        {
            ret.push_back(names[index[i]]);
        }
        return ret;
    }
};
