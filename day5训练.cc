class Solution {
public:
    int StrToInt(string str) {
        string tmp=str;
        int sum=0;
        if(str[0]=='-'||str[0]=='+')
        {
            tmp.erase(tmp.begin());
        }

        for(int i=tmp.length()-1;i>=0;i--)
        {
            if(tmp[i]<'0'||tmp[i]>'9')
            {
                return 0;
            }
            sum+=pow(10,tmp.length()-i-1)*(tmp[i]-'0');
        }
        if(str[0]=='-')
        {
            sum=-sum;
        }
        return sum;
    }
};
#include <iostream>
using namespace std;
int main() {
    int H;
    int W;
    cin>>H>>W;
    int arr[H][W];
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            arr[i][j]=0;
        }
    }
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(i-2<0&&j-2<0)
            {
                arr[i][j]=1;
            }
            if(i-2>=0&&arr[i-2][j]!=1)
            {
                arr[i][j]=1;
            }
            if(j-2>=0&&arr[i][j-2]!=1)
            {
                arr[i][j]=1;
            }
            // if(arr[i-2][j-2]!=1)
            // {
            //     arr[i][j]=1;
            // }
        }
    }
    int sum=0;
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            sum+=arr[i][j];
        }
    }
cout<<sum;
}
