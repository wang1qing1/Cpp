#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        if(n==0)return 0;
        int ret=0;
        while(n/3)
        {
            ret+=(n/3);
            n=(n%3+(n/3));
        }
        if(n==2)ret++;
        cout<<ret<<endl;
    }
}
// 64 位输出请用 printf("%lld")