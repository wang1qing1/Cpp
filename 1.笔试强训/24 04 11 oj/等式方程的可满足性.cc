
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> setfind(26,-1);
        auto findroot=[&setfind](int x) {
            while(setfind[x]>=0)x=setfind[x];
            return x;
        };
        for(auto &str:equations)
        {
            if(str[1]=='=')
            {
                int aroot=findroot(str[0]-'a');
                int broot=findroot(str[3]-'a');
                if(aroot!=broot)
                {
                    setfind[aroot]+=setfind[broot];
                    setfind[broot]=aroot;
                }
            }
        }
        for(auto &str:equations)
        {
            if(str[1]=='!')
            {
                int aroot=findroot(str[0]-'a');
                int broot=findroot(str[3]-'a');
                if(aroot==broot)
                {
                    return false;
                }
            }
        }
        return true;
    }
};