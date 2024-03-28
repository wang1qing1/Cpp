#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        long long d1=1;long long d2=2;long long d3;
        for(int i=3;i<=n;i++)
        {
            d3=d2+d1;
            d1=d2;
            d2=d3;
        }
        if(n==1)cout<<1<<endl;
        else if(n==2)cout<<2<<endl;
        else cout<<d3<<endl;
    }
}
// 64 位输出请用 printf(\"%lld\")