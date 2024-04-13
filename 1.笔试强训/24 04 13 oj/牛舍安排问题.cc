class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param houses int整型vector 
     * @param k int整型 
     * @return int整型
     */
    set<int> path;
    int ret=0x3f3f3f3f;
    int sum(vector<int>& houses)
    {
        int ret=0;
        for(int i=0;i<houses.size();i++)
        {
            if(path.find(i)==path.end())
            {
                int tmp=0x3f3f3f3f;
                for(auto e:path)
                {
                    tmp=min(abs(houses[i]-houses[e]),tmp);
                }
                ret+=tmp;
            }
        }
        return ret;
    }
    void dfs(vector<int>& houses,int begin,int k)
    {
        if(path.size()==k)
        {
            ret=min(sum(houses),ret);
        }
        for(int i=begin;i<houses.size();i++)
        {
            path.insert(i);
            dfs(houses,i+1,k);
            path.erase(i);
        }
    }
    int minTotalDistance(vector<int>& houses, int k) {
        dfs(houses,0,k);
        return ret;
    }
};