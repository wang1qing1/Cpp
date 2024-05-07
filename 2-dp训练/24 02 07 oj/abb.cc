#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

int main() {
    int n;
    cin>>n;
    string str;
    while (cin>>str) { // 注意 while 处理多个 case
        vector<map<char,int>> hash(n+1);
        long long ret=0;
        for(int i=n-1;i>=0;i--)
        {
            hash[i]=hash[i+1];
            if(i+1<n)hash[i][str[i+1]]++;
            
            for(auto& [a,b]:hash[i])
            {
                if(b>=2&&str[i]!=a)
                {
                    ret+=(b*(b-1)/2);
                }   
            }
        }
        cout<<ret<<endl;
    }
}
// 64 位输出请用 printf("%lld")