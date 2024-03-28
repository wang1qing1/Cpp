#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<string> v;
        cin.get();
        for(int i=0;i<n;i++)
        {
            string name;
            getline(cin,name);
            if(name.find(',')==string::npos&&name.find(' ')==string::npos)v.push_back(name);
            else
            {
                string s("\"");
                v.push_back(s+name+s);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i<n-1)cout<<v[i]<<", ";
            else cout<<v[i]<<endl;
        }
    }
}
