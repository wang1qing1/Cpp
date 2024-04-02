#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string str;
    while (cin >> str) { // 注意 while 处理多个 case
        unordered_map<char,int> hash;
        for(auto e:str)hash[e]++;
        
        char ch=' ';
        for(auto e:str)
        {
            if(hash[e]==1)
            {
                ch=e;
                break;
            }            
        }
        if(ch==' ')cout<<-1<<endl;
        else cout<<ch<<endl;

    }   
}
// 64 位输出请用 printf("%lld")