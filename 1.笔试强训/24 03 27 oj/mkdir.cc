#include <iostream>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case  
        vector<string> vstr(n);
        for(auto &e:vstr)cin>>e;
        sort(vstr.begin(),vstr.end());
        vector<bool> flag(n,true);
        for(int i=0;i<vstr.size()-1;i++)
        {
            if(vstr[i]==vstr[i+1])flag[i]=false;
            else if(strstr(vstr[i+1].c_str(),vstr[i].c_str())&&vstr[i+1][vstr[i].size()]=='/') flag[i]=false;
        }
        for(int i=0;i<vstr.size();i++)
        {
            if(flag[i])cout<<"mkdir -p "<<vstr[i]<<endl;
        }
        cout<<endl;
       
    }
}
