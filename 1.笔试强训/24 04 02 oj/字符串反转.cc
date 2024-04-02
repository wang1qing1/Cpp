#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string str;
    while (cin >> str) { // 注意 while 处理多个 case
        
        reverse(str.begin(),str.end());
        cout<<str<<endl;
    }
}
// 64 位输出请用 printf("%lld")