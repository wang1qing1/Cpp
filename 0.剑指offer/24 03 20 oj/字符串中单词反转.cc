class Solution {
public:
    string reverseMessage(string message) {
        int left=0;int right=message.size()-1;
        while(left<message.size())
        {
            if(message[left]!=' ')
            {
                break;
            }
            left++;
        }
        while(right>=0)
        {
            if(message[right]!=' ')break;
            right--;
        }
        if(left>right) return string();
        string tmpstr(message.begin()+left,message.begin()+right+1);
        int i=0;
        while(i<tmpstr.size())
        {
            if(tmpstr[i]==' '&&tmpstr[i+1]==' ')
            {
                tmpstr.erase(i+tmpstr.begin());
                continue;
            }
            i++;
        }
        if(tmpstr.empty())return tmpstr;

        int l=0;int r=0;
        while(r<tmpstr.size())
        {
            while(r<tmpstr.size()&&tmpstr[r]!=' ')r++;
            reverse(tmpstr.begin()+l,tmpstr.begin()+r);
            r++;
            l=r;
        }
        reverse(tmpstr.begin(),tmpstr.end());


        return tmpstr;
    }
};