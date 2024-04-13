#include <cstdio>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @param words string字符串vector 
     * @return int整型vector
     */
    vector<int> findSubstring(string s, vector<string>& words) {
        int nlen=words[0].length()*words.size();
        int len=words[0].size();
        vector<int> ret;
        if(nlen>s.size())return ret;
        for(int i=0;i<=s.size()-nlen;i++)
        {
            string tmp(s.begin()+i,s.begin()+nlen+i);
            set<string> hash;
            for(int j=0;j<words.size();j++)
            {
                string str(tmp.begin()+j*len,tmp.begin()+(j+1)*len);
                hash.insert(str);
            }
            bool flag=true;
            for(auto& e:words)
            {
                if(hash.find(e)==hash.end())
                {
                    flag=false;
                    break;
                }
            }
            if(flag)ret.push_back(i);
        }
        return ret;
    }
};