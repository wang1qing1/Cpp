#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool isBrother(string& root,unordered_map<char,int>& hash,string &str)
{
    if(root==str)return false;
    unordered_map<char,int> hashstr;
    for(auto e:str)hashstr[e]++;
    if(hash.size()!=hashstr.size())return false;
    for(auto [a,b]:hashstr)
    {
        if(hash.find(a)==hash.end()||hash[a]!=b)return false;
    }

    return true;
}

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<string> vstr(n);
        for(auto &e:vstr) cin>>e;
        string rootstr;cin>>rootstr;
        int k;cin>>k;
        unordered_map<char,int> hash;
        for(auto e:rootstr)hash[e]++;
        vector<string> brother;
        for(auto& e:vstr)
        {
            if(isBrother(rootstr, hash, e))
            {
                brother.push_back(e);
            }
            
        }
        sort(brother.begin(),brother.end());
        cout<<brother.size()<<endl;
        if(k<brother.size())cout<<brother[k-1]<<endl;
    }
    return 0;
}
