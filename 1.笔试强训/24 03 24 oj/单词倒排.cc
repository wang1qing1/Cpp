#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string str;
    while (getline(cin,str)) { // 注意 while 处理多个 case
        string tmpstr;
        int i=0;
        while(i<str.size())
        {
            if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')
            {
                tmpstr.push_back(str[i]);
                i++;
            }
            else
            {
                tmpstr.push_back(' ');
                i++;
                while(i<str.size()&&!(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z'))i++;
            }
        }
        // cout<<tmpstr<<endl;
        int left=0;
        int pos=tmpstr.find(' ');
        while(pos!=string::npos)
        {
            reverse(tmpstr.begin()+left,tmpstr.begin()+pos);
            left=pos+1;
            pos=tmpstr.find(' ',pos+1);
        }
        reverse(tmpstr.begin()+left,tmpstr.end());
        reverse(tmpstr.begin(),tmpstr.end());
        cout<<tmpstr<<endl;

    }
}
