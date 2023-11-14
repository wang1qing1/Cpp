class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        int st=1;
        string numstr=to_string(st);
        string ret;
        for(int i=2;i<=n;i++)
        {
             ret="";
            int left=0,right=0;
            for(;right<numstr.size();right++)
            {
                if(numstr[left]!=numstr[right])
                {
                    ret+=to_string(right-left);
                    ret+=numstr[left];
                    left=right;
                } 
            }
            ret+=to_string(right-left);
            ret+=numstr[left];
            numstr=ret;
        }
        return ret;
    }
};