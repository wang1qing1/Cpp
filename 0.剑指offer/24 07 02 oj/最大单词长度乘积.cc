class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<bool>> hash(words.size(),vector<bool>(26,false));
        for(int i=0;i<words.size();i++)
        {
            for(auto e:words[i])hash[i][e-'a']=true;
        }
        int ret=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                int flag=true;
                for(int k=0;k<26;k++)
                {
                    if(hash[i][k]&&hash[j][k])
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)ret=max((size_t)ret,words[i].size()*words[j].size());
            }
        }
        return ret;
    }
};