class Solution {
public:
    string reverseWords(string& s) {
        string str;
        int index=0;
        int one=0;
        for(auto e:s)
        {
            if(e!=' ')
            {
                str.push_back(e);
                one=0;
            }
            else if(e==' ' && one==0)
            {
                 str.push_back(e);
                one++;
            }
        }
        if(str[0]==' ')str.erase(0,1);
        if(str.back()==' ')str.pop_back();
        auto left=str.begin();
        auto it=str.begin();
        for( it=str.begin();it!=str.end();it++)
        {
            if((*it)==' ')
            {
                reverse(left,it);
                left=it+1;
            }
        }
        reverse(left,it);
        reverse(str.begin(),str.end());
        return str;
    }
};