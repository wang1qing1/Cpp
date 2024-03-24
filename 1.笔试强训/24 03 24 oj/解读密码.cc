#include <iostream>
using namespace std;

int main() {
    string str;
    while (getline(cin,str)) { // 注意 while 处理多个 case
        string ret;
        for(auto e:str)
        {
            if(e>='0'&&e<='9')ret+=e;
        }
        cout<<ret<<endl;
    }
}
// 64 位输出请用 printf(\"%lld\")