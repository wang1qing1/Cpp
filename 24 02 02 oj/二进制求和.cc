class Solution {
public:
    string addBinary(string a, string b) {
        int alen=a.size()-1;
        int blen=b.size()-1;
        string ret;
        int i=0;
        while(alen>=0&&blen>=0)
        {
            int num1=a[alen]-'0';
            int num2=b[blen]-'0';
            int sum=i+num1+num2;
            i=sum/2;
            ret+=to_string(sum%2);
            alen--;blen--;
        }
        while(alen>=0)
        {
            int num=a[alen]-'0';
            int sum=i+num;
            i=sum/2;
            ret+=to_string(sum%2);
            alen--;
        }
        while(blen>=0)
        {
            int num=b[blen]-'0';
            int sum=i+num;
            i=sum/2;
            ret+=to_string(sum%2);
            blen--;
        }
        if(i)ret+=to_string(i);
        reverse(ret.begin(),ret.end());
        return ret;
    }
};