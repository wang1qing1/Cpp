class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(n<=numRows||numRows==1)return s;
        string ret;
        int k=2*numRows-2;//关键
        //第一层每次一个，间距为K
        for(int i=0;i<n;i+=k)ret+=s[i];
        //中间层两两一对，间距为K
        for(int t=1;t<=numRows-2;t++)
        {
            for(int i=t,j=k-t;i<n||j<n;i+=k,j+=k)
            {
                if(i<n)ret+=s[i];
                if(j<n)ret+=s[j];
            }
        }
        //最后一层每次一个，间距为K
        for(int i=numRows-1;i<n;i+=k)ret+=s[i];
        return ret;
    }
            
};