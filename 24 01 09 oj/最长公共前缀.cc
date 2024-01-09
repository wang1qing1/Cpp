class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //暴力测试
        //先找到长度最短的字符串,最长公共前缀不会超过最短字符串长度
        int n=strs.size();
        size_t minlen=0x3f3f3f3f;
        for(auto &e:strs)minlen=min(minlen,e.length());
        
        int ret=0;
        for(int i=0;i<minlen;i++)
        {
            char base=strs[0][i];//base字符
            bool flag=false;
            for(auto &e:strs)//挨个与base比较
            {
                if(e[i]!=base)//不相等直接返回了
                {
                    return string(strs[0].begin(),strs[0].begin()+ret);
                }
            }
            ret++;
        }
        return string(strs[0].begin(),strs[0].begin()+ret);
    }
};