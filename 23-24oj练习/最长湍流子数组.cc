class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
        {
            return 1;
        }
        vector<int> f(n,1);
        vector<int> g(n,1);
        int maxret=1;
 

        for(int i=1;i<n;i++)
        {
          
            if(arr[i-1]<arr[i])
            {
                g[i]=f[i-1]+1;
            }
            if(arr[i-1]>arr[i])
            {
                f[i]=g[i-1]+1;
            }
            maxret=max(max(f[i],g[i]),maxret);
        }
        return maxret;
    }
};