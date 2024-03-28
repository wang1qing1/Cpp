#include <iostream>
using namespace std;

int main() {
    string bstr,sstr;
    while (cin >> bstr >> sstr) {// 注意 while 处理多个 case
        int ret=0;
        int i=0;
        while(i<=(int)bstr.size()-(int)sstr.size())
        {
            //查找子串，如果找到记录一次，并且将找到得地方剪掉
            if(bstr.substr(i,sstr.size())==sstr)
            {
                ret++;
                i+=sstr.size();
            }//没有找到就往后挪一个位置
            else i++;
        }
        cout<<ret<<endl;
    }
}
// 64 位输出请用 printf(\"%lld\")