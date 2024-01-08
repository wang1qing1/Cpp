class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char,int> hash;
        char maxchar=0;
        int maxcount=0;
        for(auto ch:s)
        {
            hash[ch]++;
            if(hash[ch]>maxcount)
            {
                maxcount=hash[ch];
                maxchar=ch;
            }
        }
        if((n+1)/2<maxcount)return "";
        string ret=s;
        int index=0;
        //处理maxchar
        for(int i=0;i<maxcount;i++)
        {
            ret[index]=maxchar;
            index+=2;
        }
        //删除maxchar
        hash.erase(maxchar);
        //处理剩下字符
        for(auto [a,b]:hash)
        {
            for(int i=0;i<b;i++)
            {
                if(index>=n)index=1;
                ret[index]=a;
                index+=2;
            }
        }
        return ret;
    }
};