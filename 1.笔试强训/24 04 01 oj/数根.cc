#include <iostream>
using namespace std;

int main() {
    string num;
    while (cin >> num) { // 注意 while 处理多个 case
        while(num.size()>=2)
        {
            long long sum=0;
            while(num.size())
            {
                sum+=(num.back()-'0');
                num.pop_back();           
            }
            num=to_string(sum);
        }
        cout<<num<<endl;
    }   
}
// 64 位输出请用 printf(\"%lld\")