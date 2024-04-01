#include <iostream>
using namespace std;

int main() {
    double a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        double r=a/(3.14*2);
        if(b>=r)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
// 64 位输出请用 printf(\"%lld\")