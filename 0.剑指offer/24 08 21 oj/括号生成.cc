class Solution {
public:
    map<char,int> hash;
    unordered_set<string> ret;
    string path;
    void dfs(vector<char>& vch)
    {
        for(int i=0;i<vch.size();i++)
        {
            path+=vch[i];
            hash[vch[i]]++;
            if((i>0&&vch[i]==vch[i-1])||hash[')']*2>vch.size()||hash['(']*2>vch.size()||hash[')']>hash['('])
            {
                path.pop_back();
                hash[vch[i]]--;
                continue;
            }
            if(hash[')']==hash['(']&&hash[')']*2==vch.size())
            {
                ret.insert(path);
            }
            dfs(vch);
            path.pop_back();
            hash[vch[i]]--; 
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<char> vch(2*n,'(');
        for(int i=n;i<2*n;i++)vch[i]=')';
        dfs(vch);
        vector<string> result;
        for(auto e:ret)
        {
            result.emplace_back(e);
        }
        return result;


    }
};
// ( ( ( ) ) )
// ( ( ( ) ) )
// ( ( ( ) ) )
// ( ( ( ) ) )
// ( ( ( ) ) )
// ( ( ( ) ) )