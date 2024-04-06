#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
       int f1=0;
       int f2=1;
       int f3=1;
        while(f2<n)
       {
            f3=f1+f2;
            f1=f2;
            f2=f3;    
       }
       cout<<min(abs(f2-n),abs(f1-n))<<endl;

    }
}
// 64 位输出请用 printf("%lld")