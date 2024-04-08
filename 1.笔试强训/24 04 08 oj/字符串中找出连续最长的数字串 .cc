#include <iostream>
#include <math.h>
using namespace std;

int main() {
    string str;
    while (getline(cin,str)) { // 注意 while 处理多个 case
        int count=0;
        int ret=0;
        int pos=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]>='0'&&str[i]<='9')
            {
                count++;
            }
            else
            {
                if(ret<count)
                {
                    ret=count;
                    pos=i;
                }
                count=0;
            }
        }
        if(ret<count)
        {
            ret=count;
            pos=str.size();
        }
        string tmp(str.begin()+pos-ret,str.begin()+pos);
        cout<<tmp<<endl;
    }
}
// 64 位输出请用 printf("%lld")