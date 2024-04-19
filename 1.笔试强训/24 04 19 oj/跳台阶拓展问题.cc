#include <iostream>
#include <vector>
using namespace std;

int getsum(int pos,vector<int>& arr)
{
    int sum=0;
    for(int i=1;i<pos;i++)
    {
        sum+=arr[i];
    }
    return sum;
}

int main() {
    int n;
    vector<int> arr(21);
    arr[1]=1;
    arr[2]=2;
    //
    for(int i=3;i<=20;i++)
    {
        arr[i]=getsum(i,arr)+1;
    }
    while (cin >> n) { // 注意 while 处理多个 case
       cout<< arr[n]<<endl;
    }
}
// 64 位输出请用 printf("%lld")