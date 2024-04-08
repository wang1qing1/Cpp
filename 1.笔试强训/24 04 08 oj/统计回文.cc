#include <iostream>
#include <algorithm>
using namespace std;

bool isOk(const string & str)
{
    string tmp=str;
    reverse(tmp.begin(),tmp.end());
    return tmp==str;
}

int main() {
    string a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        int count=0;
        for(int i=0;i<=a.size();i++)
        {
            string tmp(a.begin(),a.begin()+i);
            tmp+=b;
            tmp+=string(a.begin()+i,a.end());
            if(isOk(tmp))
            {
                count++;
            }
        }
        cout<<count<<endl;

    }
}
// 64 位输出请用 printf("%lld")