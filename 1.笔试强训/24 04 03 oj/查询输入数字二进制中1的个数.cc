#include <iostream>
using namespace std;

int main() {
   int num;
    while (cin >> num) { // 注意 while 处理多个 case
        int ret=0;
        for(int i=0;i<=31;i++)
        {
            if(num&(1<<i))ret++;
        }
        cout<<ret<<endl;
    }
}
// 64 位输出请用 printf("%lld")