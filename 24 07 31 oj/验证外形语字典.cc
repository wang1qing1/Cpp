class Solution {
public:
    bool strcom(string& str1,string& str2)
    {
        int len1=str1.size();
        int len2=str2.size();
        int len=min(len1,len2);
        for(int i=0;i<len;i++)
        {
            if(hash[str1[i]]>hash[str2[i]]) return false;
            else if(hash[str1[i]]<hash[str2[i]]) return true; 
        }
        if(len1<=len2)return true;
        else return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.size();i++) hash[order[i]]=i;
        for(int i=0;i<words.size()-1;i++)
        {
            if(!strcom(words[i],words[i+1]))
            {
                return false;
            }
        }
        return true;
    }
    unordered_map<char,int> hash;
};