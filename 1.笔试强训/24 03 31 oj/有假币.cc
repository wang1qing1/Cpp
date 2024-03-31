#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        int count=0;
        if(n==0)return 0;
        while(n>1)
        {
            if(n%3)
            {
                //调整为3的倍数
                n+=(3-(n%3));
            }
            else
            {
                n/=3;
                count++;
            }
        }
        cout<<count<<endl;
    }
}
// 64 位输出请用 printf(\"%lld\")