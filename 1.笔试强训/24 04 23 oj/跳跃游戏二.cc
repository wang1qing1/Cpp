#include <bits/types/struct_tm.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        for(auto& e:arr)cin>>e;
        int ret=arr.back();
        int pos=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(pos<=arr[i]+i)
            {
                ret+=arr[i];
                pos=i;
            }
        }
        if(pos==0)cout<<ret<<endl;
        else cout<<-1<<endl;

    }
}
