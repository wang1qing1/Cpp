#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string A;
    string B;
    
    while (cin >> A >> B) { // 注意 while 处理多个 case
       unordered_map<char,int> hasha;
       unordered_map<char,int> hashb;
       for(auto e:A)hasha[e]++;
       for(auto e:B)hashb[e]++;
       bool flag=true;
       for(auto [a,b]:hashb)
       {
            if(hasha.find(a)==hasha.end()||hasha[a]<b)flag=false;
       }
       if(flag)cout<<"Yes"<<endl;
       else cout<<"No"<<endl;


    }
}
// 64 位输出请用 printf(\"%lld\")