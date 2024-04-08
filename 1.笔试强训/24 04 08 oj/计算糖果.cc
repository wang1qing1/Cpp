#include <iostream>
using namespace std;

int main() {
    int a, b,c,d;
    while (cin >> a >> b>>c>>d) { // 注意 while 处理多个 case
       
       int A=(a+c)/2;
       int B=(b+d)/2;
       int C=d-B;
       if(A<0||B<0||C<0||(a+c)%2==1||(b+d)%2==1)cout<<"No"<<endl;
       else printf("%d %d %d\n",A,B,C);
    }
}
// 64 位输出请用 printf("%lld")