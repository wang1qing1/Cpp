class Solution {
public:
    int toint(const char ch)
    {
        return ch-'0';
    }
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int n=min(a.size(),b.size());
        int i=0;
        int in=0;
        string ret;
        while(i<n)
        {
            ret+=((toint(a[i])+toint(b[i])+in)%2+'0');
            in=(toint(a[i])+toint(b[i])+in)/2;
            i++;
        }
        while(i<b.size())
        {
            ret+=((toint(b[i])+in)%2+'0');
            in=(toint(b[i])+in)/2;
            i++;
        }
        while(i<a.size())
        {
            ret+=((toint(a[i])+in)%2+'0');
            in=(toint(a[i])+in)/2;
            i++;
        }
        if(in)ret+='1';
        reverse(ret.begin(),ret.end());
        return ret;
    }
};