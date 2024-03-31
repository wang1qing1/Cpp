#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        if(n==0)return 0;
        long long x=pow(5,n)-4;
        long long y=pow(4,n)+n-4;
        cout<<x<<" "<<y<<endl;
        
    }
}
