class Solution {
public:
    bool isPalindrome(string& s) {
        //预处理
        string str;
        for(auto e:s)
        {
            if(e>='A'&&e<='Z')str.push_back(e+('a'-'A'));
            else if(e>='a'&&e<='z'||e>='0'&&e<='9')str.push_back(e);
        }
        int left=0;
        int right=str.size()-1;
        while(left<right)
        {
            if(str[left]==str[right])
            {
                left++;
                right--;
            }
            else
            return false;
        }
        return true;
    }
};