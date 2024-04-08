#include <iostream>
#include <algorithm>
using namespace std;
char arr[17]="0123456789ABCDEF";

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        
        string ret;
        int tmp=a;
        a=abs(a);
        while(a)
        {
            ret+=arr[a%b];
            a/=b;
        }
        if(tmp<0)ret+="-";
        if(ret.empty())
        {
            cout<<"0"<<endl;
        }
        else 
        {
            reverse(ret.begin(),ret.end());
            cout<<ret<<endl;
        }
   }
   
}
// 64 位输出请用 printf("%lld")