class Solution {
public:
    bool com(map<char,int>& hashs,map<char,int>& hasht)
    {
        for(auto [a,b]:hashs)
        {
            if(b<hasht[a])return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(t.size()>s.size())return "";
        map<char,int> hasht;
        for(auto e:t)hasht[e]++;
        map<char,int> hashs;
        int left=0;
        int right=0;
        int retleft=0;
        int retright=0x3f3f3f3f;
        while(right<s.size())
        {
            //字符在t中
            if(hasht.find(s[right])!=hasht.end())
            {
                hashs[s[right]]++;
            }
            right++;
            while(hashs.size()==hasht.size()&&right-left>=t.size()&&com(hashs,hasht))
            {
                if((right-left)<(retright-retleft))
                {
                    retleft=left;
                    retright=right;
                }
                if(hashs.find(s[left])!=hashs.end())
                {
                    hashs[s[left]]--;
                    if(hashs[s[left]]==0)hashs.erase(s[left]);
                }
                left++;
            }
        }
        if(retright==0x3f3f3f3f)return "";
        else return string(s.begin()+retleft,s.begin()+retright);
    }
};

