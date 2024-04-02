#include <iostream>
using namespace std;

int GetMaxB(int a,int b)
{
    int tmp=0;
    for(int i=1;i<=b;i++)
    {
        if((a*i)%b==0)
        {   
            tmp=i*a;
            break;
        }   
    }
    return a*b/tmp;
}
int main() {
    int n, ph;
    while (cin >> n >> ph) { // 注意 while 处理多个 case
        while(n--)
        {
            int bi;cin>>bi;
            if(bi<=ph)ph+=bi;
            else
            {
                ph+=GetMaxB(bi,ph);
            }
        }
        cout<<ph<<endl;
    }
}
// 64 位输出请用 printf("%lld")