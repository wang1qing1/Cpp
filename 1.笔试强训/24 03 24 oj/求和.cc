#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int sum=0;
int ret=0;
void dfs(int n,int target,int begin)
{
    if(sum==target)
    {
        ret++;
        return;
    }
    for(int i=begin;i<=n;i++)
    {
        sum+=i;
        dfs(n,target,i+1);
        sum-=i;
    }
}

int main() {
    int n, target;
    while (cin >> n >> target) { // 注意 while 处理多个 case
        dfs(n,target,1);
        cout<<ret<<endl;
    }
}
// 64 位输出请用 printf(\"%lld\")