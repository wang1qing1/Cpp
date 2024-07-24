class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto e:s)
        {
            if(e>='A'&&e<='Z')
            {
                str+=(e+('a'-'A'));
            }
            else if((e>='a'&&e<='z')||(e>='0'&&e<='9'))
            {
                str+=e;
            }
        }
        string tmpstr=str;
        reverse(str.begin(),str.end());
        return tmpstr==str;
    }
};