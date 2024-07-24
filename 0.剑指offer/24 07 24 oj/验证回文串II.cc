class Solution {
public:
    bool Isrome(string& str)
    {
        const string tmpstr=str;
        reverse(str.begin(),str.end());
        return str==tmpstr;
    }
    bool validPalindrome(string s) {
        string tmp=s;
        if(Isrome(tmp))return true;
        int i=0;
        while(i<s.size()/2)
        {
            if(s[i]!=s[s.size()-1-i])
            {
                string str1=s.substr(0,i)+s.substr(i+1);
                string str2=s.substr(0,s.size()-1-i)+s.substr(s.size()-i);
                return Isrome(str1)|| Isrome(str2);
            }
            i++;
        }
        return false;
    }
};
