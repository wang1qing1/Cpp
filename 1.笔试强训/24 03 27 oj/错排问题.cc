#include <iostream>
using namespace std;

int main() 
{
    int a;
    while (cin >> a) 
    { // 注意 while 处理多个 case
        long long d1=0;long long d2=1;
        long long d3;
        for(int i=3;i<=a;i++)
        {
            d3=(d2+d1)*(i-1);
            d1=d2;
            d2=d3;
        }
        cout<<d2<<endl;
    }
}
// 64 位输出请用 printf(\"%lld\")