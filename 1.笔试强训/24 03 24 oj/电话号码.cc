#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    
    unordered_set<string> hashset;
    unordered_map<char,char> hashmap;
    for(char ch='A';ch<='Z';ch++)
    {
        if(ch>='A'&&ch<='C')hashmap[ch]='2';
        else if(ch>='D'&&ch<='F')hashmap[ch]='3';
        else if(ch>='G'&&ch<='I')hashmap[ch]='4';
        else if(ch>='J'&&ch<='L')hashmap[ch]='5';
        else if(ch>='M'&&ch<='O')hashmap[ch]='6';
        else if(ch>='P'&&ch<='S')hashmap[ch]='7';
        else if(ch>='T'&&ch<='V')hashmap[ch]='8';
        else hashmap[ch]='9';
    }
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        string str;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            string tmpstr;
            int pos=0;
            while(pos<str.size())
            {
                if(str[pos]=='-')pos++;
                else if(str[pos]>='A'&&str[pos]<='Z')
                {
                    tmpstr+=hashmap[str[pos]];
                    if(tmpstr.size()==3)tmpstr+='-';
                    pos++;
                }
                else 
                {
                    tmpstr+=str[pos];
                    if(tmpstr.size()==3)tmpstr+='-';
                    pos++;
                }
            }
            hashset.insert(tmpstr);
        }
        vector<string> vvstr(hashset.begin(),hashset.end());
        sort(vvstr.begin(),vvstr.end());
        for(auto&e:vvstr)cout<<e<<endl;
         hashset.clear();
        cout<<endl;
       

    }
}
// 64 位输出请用 printf(\"%lld\")