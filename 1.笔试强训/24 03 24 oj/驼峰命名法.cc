#include <iostream>
using namespace std;

int main() {
    string str;
    while (cin >> str) { // 注意 while 处理多个 case
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='_')
            {
                str[i+1]=str[i+1]+'A'-'a';
                str.erase(i,1);
            }
        }
        cout<<str<<endl;
    }
}

