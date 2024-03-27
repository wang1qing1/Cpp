#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        unordered_map<string,string> hash;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            string number;
            string oper;
            cin>>number>>oper;
           
            if(hash.empty())
            {
                 hash[number]=oper;
                 sum=max(sum,(int)hash.size());
            }
            else
            {
                if(hash.find(number)!=hash.end())
                {
                    hash.erase(number);
                }
                else
                {
                    hash[number]=oper;
                    sum=max(sum,(int)hash.size());
                }
            }
        }
        cout<<sum<<endl;
    }
}
// 64 位输出请用 printf(\"%lld\")