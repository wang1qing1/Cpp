#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        for(auto& e:arr)cin>>e;
        int maxpath=arr[0];
        for(int i=1;i<n;i++)
        {
            if(maxpath>=i)
            {
                maxpath=max(arr[i]+i,maxpath);
            }
            else break;
        }
        if(maxpath>=n-1)cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        vector<bool> dp(n,false);
        dp[0]=true;
        for(auto& e:arr)cin>>e;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(arr[j]&&dp[j]&&arr[j]+j>=i)
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        if(dp[n-1])cout<<"true"<<endl;
        else cout<<"false"<<endl;

    }
}
