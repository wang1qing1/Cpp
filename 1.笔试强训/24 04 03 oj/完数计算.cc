#include <iostream>
using namespace std;

bool IsPerfectNum(int num)
{
    int ret=0;
    for(int i=1;i<=num/2;i++)
    {
        if(num%i==0)ret+=i;
    }
    if(ret==num) 
    {
        return true;
    }
    return false;
}

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        int ret=0;
        for(int i=1;i<=n;i++)
        {
            if(IsPerfectNum(i)) ret++;
        }
        cout<<ret<<endl;
    }
}
// 64 位输出请用 printf("%lld")