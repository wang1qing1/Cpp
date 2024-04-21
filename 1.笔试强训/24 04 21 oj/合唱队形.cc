#include <iostream>
#include <vector>
using namespace std;

int GetUpMax(const vector<int>&arr)
{
    vector<int> dp(arr.size(),1);
    int ret=(arr.size()>0?1:0);
    for(int i=1;i<arr.size();i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i]>arr[j])dp[i]=max(dp[i],dp[j]+1);
        }
        ret=max(ret,dp[i]);
    }
    return ret;
}
int GetDownMax(const vector<int>& arr)
{
    vector<int> dp(arr.size(),1);
    int ret=(arr.size()>0?1:0);
    for(int i=1;i<arr.size();i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i]<arr[j])dp[i]=max(dp[i],dp[j]+1);
        }
        ret=max(ret,dp[i]);
    }
    return ret;
}

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> arr(n);
        for(auto &e:arr)cin>>e;
        int ret=100000;
        vector<int> tmp;
        tmp.push_back(arr[0]);
        //去除连续重复数据
        for(int i=1;i<n;i++)
        {
            if(arr[i]!=tmp.back())tmp.push_back(arr[i]);
        }
        //[0,i]找最长连续递增,[i+1,n]找最长连续递减
        for(int i=0;i<=tmp.size();i++)
        {
            vector<int> left(tmp.begin(),tmp.begin()+i);
            vector<int> right(tmp.begin()+i,tmp.end());
            int n1=GetUpMax(left);
            int n2=GetDownMax(right);
            ret=min(n-(n1+n2),ret);
        }
        cout<<ret<<endl;
    }
}
