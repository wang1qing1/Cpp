class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numFruits int整型 
     * @param prerequisites int整型vector<vector<>> 
     * @return bool布尔型
     */
    bool canEatAllFruits(int numFruits, vector<vector<int> >& pre) {
        map<int,set<int>> hash;
        for(auto& v:pre)
        {
            hash[v[1]].insert(v[0]);
        }
        queue<int> q;
        for(int i=0;i<numFruits;i++)
        {
            if(hash[i].empty())q.push(i);
        }
        if(q.empty())return false;
        while(!q.empty())
        {
            int a=q.front();q.pop();
            for(auto &[c,d]:hash)
            {
                if(d.find(a)!=d.end())
                {
                    d.erase(a);
                    if(d.empty())q.push(c);
                }
            }
        }
        for(auto& [a,b]:hash)if(!b.empty())return false;
        return true;
    }
};