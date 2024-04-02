#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void WashP(vector<int>& arr)
{
    vector<int> v1(arr.begin(),arr.begin()+arr.size()/2);
    vector<int> v2(arr.begin()+arr.size()/2,arr.end());
    int index=0;
    for(int i=0;i<arr.size()/2;i++)
    {
        arr[index++]=v1[i];
        arr[index++]=v2[i];
    }
}

int main() {
    int m;
    while (cin >> m) { // 注意 while 处理多个 case
        while(m--)
        {
            int n,k;
            cin>>n>>k;
            vector<int> arr(2*n);
            for(auto& e:arr)cin>>e;
            while(k--)
            {
                WashP(arr);
            }
            for(auto e:arr)cout<<e<<" ";
            cout<<endl;
        }
    }
}
// 64 位输出请用 printf("%lld")