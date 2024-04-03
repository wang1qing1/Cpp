#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string str;char ch;
    getline(cin,str);
    while (cin >>ch) { // 注意 while 处理多个 case
        unordered_map<char,int> hash;
        for(auto e:str)
        {
            hash[e]++;
        }
        int p='a'-'A';
        if(ch>='a'&&ch<='z')        
            cout<<hash[ch]+hash[ch-p]<<endl;
        else if(ch>='A'&&ch<='Z')
            cout<<hash[ch]+hash[ch+p]<<endl;
        else cout<<hash[ch]<<endl;
    }
}
// 64 位输出请用 printf(\"%lld\")