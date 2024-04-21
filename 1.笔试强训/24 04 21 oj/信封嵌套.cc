#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;
int GetUpMax(const vector<PII>&arr)
{
    vector<int> dp(arr.size(),1);
    int ret=(arr.size()>0?1:0);
    for(int i=1;i<arr.size();i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i].first>arr[j].first&&arr[i].second>arr[j].second)dp[i]=max(dp[i],dp[j]+1);
        }
        ret=max(ret,dp[i]);
    }
    return ret;
}
int main() {
    int n;
    cin >> n;
    vector<PII> arr(n);
    for(auto &[a,b]:arr)
    {
        cin>>a>>b;
    } 
    sort(arr.begin(),arr.end(),[](const PII& e1,const PII& e2){
        return e1.second<e2.second;
    });
    cout<<GetUpMax(arr)<<endl;
    return 0;
}
