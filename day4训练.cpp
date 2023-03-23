#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    long long num=0;
    int k=0;
    string strnum;
    cin>>num>>k;
    int numm=num;
    if(num==0)
    {
        cout<<'0'<<endl;
    }
    if(num<0)
    {
        num=-num;
    }
    while(num)
    {
        int c=(num%k);
        if(c>=10)
        {
            strnum.push_back((c-10)+'A');
        }
        else
        {
            strnum.push_back(c+'0');   
        }
        num/=k;
    }
    reverse(strnum.begin(),strnum.end());
    if(numm<0)
    {
        cout<<'-';
    }
    cout<<strnum;
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    
    int x1,x2,x3,x4;
    cin>>x1>>x2>>x3>>x4;
    double A=(x1+x3)/2.0;
    double B=A-x1;
    double C=x4-B;
    if(B-C!=x2)
    {
        cout<<"No"<<endl;
        return 0;
    }
    if(A<0||B<0||C<0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    
    if(A-(int)A!=0.0||B-(int)B!=0.0||C-(int)C!=0.0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<(int)A<<" "<<(int)B<<" "<<(int)C;
    
    return 0;
}