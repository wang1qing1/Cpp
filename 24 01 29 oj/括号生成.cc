class Solution {
public:
    vector<string> ret;
    string path;
    int left=0;
    int right=0;
    void dfs(int n)
    {
        if(right==n)
        {
            ret.push_back(path);
            return ;
        }
        if(left<n)
        {
            path+="(";
            left++;
            dfs(n);
            left--;
            path.pop_back();
        }
        if(right<left)
        {
            path+=")";
            right++;
            dfs(n);
            right--;
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs(n);
        return ret;
    }
};
};