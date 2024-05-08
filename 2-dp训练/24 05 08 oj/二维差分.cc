#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>> arr(n,vector<long long>(m));
    vector<vector<int>> tmp(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>tmp[i][j];
            arr[i][j]=tmp[i][j];
            if(j>0)
            {
                arr[i][j]-=tmp[i][j-1];
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        int x1,y1,x2,y2,k;
        cin>>x1>>y1>>x2>>y2>>k;
        x1--;x2--;y1--;y2--;
        for(int i=x1;i<=x2;i++)
        {
            arr[i][y1]+=k;
            if(y2+1<m)arr[i][y2+1]-=k;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i][0]<<' ';
        for(int j=1;j<m;j++)
        {
            arr[i][j]=arr[i][j-1]+arr[i][j];
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
}
// 64 位输出请用 printf("%lld")