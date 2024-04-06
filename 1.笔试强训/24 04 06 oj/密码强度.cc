#include <iostream>
using namespace std;

bool isaz(char ch)
{
    if(ch>='a'&&ch<='z')  return true;
    return false;
}
bool isAZ(char ch)
{
    if(ch>='A'&&ch<='Z')  return true;
    return false;
}
bool is19(char ch)
{
    if(ch>='0'&&ch<='9')return true;
    return false;
}

int main() {
    string  str;
    while (cin >> str) { // 注意 while 处理多个 case
        int numa=0;
        int numA=0;
        int num1=0;
        int num_=0;
        for(auto e:str)
        {
            if(isaz(e))numa++;
            else if(isAZ(e))numA++;
            else if(is19(e))num1++;
            else num_++;
        }
        int sum=0;
        if(str.length()>=0&&str.length()<=4)sum+=5;
        else if(str.length()>=5&&str.length()<=7)sum+=10;
        else sum+=25;

        if(numa==0&&numA==0)sum+=0;
        else if(numa==0&&numA>0||numA==0&&numa>0) sum+=10;
        else sum+=20;

        if(num1==0)sum+=0;
        else if(num1==1)sum+=10;
        else sum+=20;

        if(num_==0)sum+=0;
        else if(num_==1)sum+=10;
        else sum+=25;

        if(num1>0&&numa>0&&numA>0&&num_>0)sum+=5;
        else if(num1>0&&numa+numA>0&&num_>0)sum+=3;
        else if(num1>0&&numa+numA>0)sum+=2;

        if(sum>=90)cout<<"VERY_SECURE"<<endl;
        else if(sum>=80)cout<<"SECURE"<<endl;
        else if(sum>=70)cout<<"VERY_STRONG"<<endl;
        else if(sum>=60)cout<<"STRONG"<<endl;
        else if(sum>=50)cout<<"AVERAGE"<<endl;
        else if(sum>=25)cout<<"WEAK"<<endl;
        else if(sum>=0)cout<<"VERY_WEAK"<<endl;
        

    }
}
// 64 位输出请用 printf("%lld")