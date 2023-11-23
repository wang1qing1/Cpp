class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")return "0";
        int n1=num1.size();
        int n2=num2.size();
        int n=n1+n2;
        vector<int> tmp(n-1,0);

        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<num2.size();i++)
        {
            for(int j=0;j<num1.size();j++)
            {
                
                tmp[i+j]+=(num1[j]-'0')*(num2[i]-'0');
            }   
        }
        string ret;
        int t=0;
        for(int i=0;i<tmp.size();i++)
        {
            ret+=(tmp[i]+t)%10 +'0';
            t=(tmp[i]+t)/10;
            if(i==tmp.size()-1&&t!=0) ret +=(t+'0');
        }
        
        reverse(ret.begin(),ret.end());
        return ret;
    }
};