#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    int n=0;
    cin>>n;
    vector<string> vv;
    while(n--)
    {
        string str;
        cin>>str;
        vv.push_back(str);
    }
    int f1=1;//字典排序
    int f2=1;//长度排序
    for(int i=0;i<vv.size()-1;i++)
    {
        if(vv[i]>vv[i+1])
        {
            f1=0;
        }
        if(vv[i].length()>vv[i+1].length())
        {
            f2=0;
        }
    }
    if(f1&&f2)
    {
        cout<<"both"<<endl;
    }
    else if(f1)
    {
        cout<<"lexicographically"<<endl;
    }
    else if(f2)
    {
        cout<<"lengths"<<endl;
    }
    else
    {
        cout<<"none"<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
        if((b*i)%a==0)
        {
            cout<<b*i<<endl;
            break;
        }
    }
    return 0;
}
