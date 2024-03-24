#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <math.h>

using namespace std;

int main() {
    string mess;
    vector<pair<string,int>> vstr;
    while(getline(cin,mess)) { // 注意 while 处理多个 case    
        int ipos=mess.rfind('\\');
        int apos=mess.rfind(' ');
        string tmpstr(mess.begin()+ipos+1,mess.begin()+apos);//文件名称
        if(tmpstr.size()>16)tmpstr=string(tmpstr.end()-16,tmpstr.end());//长度超过16
        tmpstr+=string(mess.begin()+apos,mess.end());//加上行号
        int pos=0;
        for(pos=0;pos<vstr.size();pos++)
        {
            if(vstr[pos].first==tmpstr)
            {
                vstr[pos].second++;
                break;
            }
        }
        if(pos==vstr.size())vstr.push_back({tmpstr,1});
    }

    
    for(int i=(vstr.size()<8)?0:vstr.size()-8;i<vstr.size();i++)
    {
        auto &[a,b]=vstr[i];
        cout<<a<<' '<<b<<endl;
    }

}
