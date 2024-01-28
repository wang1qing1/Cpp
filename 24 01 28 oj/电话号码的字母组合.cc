class Solution {
public:
    vector<string> v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ret;
    string path;
    int n;
    void dfs(int i,const string& digits)
    {
        if(i==digits.size())
        {
            ret.push_back(path);
            return ;
        }
        int pos=digits[i]-'0';
        for(int j=0;j<v[pos].size();j++)
        {
            path+=v[pos][j];
            dfs(i+1,digits);
            path.pop_back();//恢复现场
        }
    }
    vector<string> letterCombinations(string digits) {
        
        n=digits.size();
        if(n==0)return {};
        int len=0;
        string tmp;
        dfs(0,digits);
        return ret;
    }
};
};