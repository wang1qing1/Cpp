class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        string ret;
        int n=s.length();
        int k=2*numRows-2;
        for(int i=0;i<n;i+=k) ret+=s[i];

        for(int t=1;t<=numRows-2;t++)
        {
            for(int i=t,j=k-t;i<n||j<n;i+=k,j+=k)
            {
                if(i<n&&i!=t-1) ret+=s[i];
                if(j<n) ret+=s[j];
            }
        }
        for(int i=numRows-1;i<n;i+=k) ret+=s[i];

        return ret;        
    }
};