#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        int ret=0;
        int count=0;
        for(int i=0;i<=31;i++)
        {
            if((1<<i)&n)
            {
                count++;
            }
            else {
                ret=max(ret,count);
                count=0;
            }
        }
        ret=max(ret,count);
        cout<<ret<<endl;
    }
}
// 64 位输出请用 printf("%lld")