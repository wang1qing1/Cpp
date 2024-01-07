class Solution {
public:
    unordered_map<int,int> hash;//<n,ret>
    int dfs(long long n)
    {
        if(hash.find(n)!=hash.end())return hash[n];
        if(n==1)return 0;
        if(n%2) 
        {
            hash[n]=min(dfs(n+1),dfs(n-1))+1;
            return hash[n];
        }
        else 
        {
            hash[n]=dfs(n/2)+1;
            return hash[n];
        }
    }

    int integerReplacement(int n) {
        return dfs(n);
    }
};