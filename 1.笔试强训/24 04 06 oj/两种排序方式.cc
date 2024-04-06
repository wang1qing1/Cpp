#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<string> vstr(n);
        for(auto& e:vstr) cin>>e;
        bool lex=true;
        bool lengths=true;
        for(int i=0;i<n-1;i++)
        {
            if(vstr[i]>=vstr[i+1])lex=false;
            if(vstr[i].length()>=vstr[i+1].length())lengths=false;
        }
        if(lex&&lengths)cout<<"both"<<endl;
        else if(lex)cout<<"lexicographically"<<endl;
        else if(lengths)cout<<"lengths"<<endl;
        else cout<<"none"<<endl;
    }
}
// 64 位输出请用 printf("%lld")