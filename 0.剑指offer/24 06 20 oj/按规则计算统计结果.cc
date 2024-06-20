class Solution {
public:
    vector<int> statisticalResult(vector<int>& arrayA) {
        vector<int> ret(arrayA.size());
        int sum=1;
        int sumtmp=1;
        int count0=0;
        for(auto e:arrayA)
        {
            sum*=e;
            if(e)
            {
                sumtmp*=e;
            }
            else count0++;
        }
        for(int i=0;i<arrayA.size();i++)
        {
            if(arrayA[i])ret[i]=sum/arrayA[i];
            else 
            {
                ret[i]=sumtmp;
                if(count0>1)ret[i]=0;
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> statisticalResult(vector<int>& arrayA) {
        int n=arrayA.size();
        if(n==0)return vector<int>();
        vector<int> arr1(n,1);arr1[0]=arrayA[0];
        vector<int> arr2(n,1);arr2[n-1]=arrayA[n-1];
        for(int i=1;i<n;i++)
        {
            arr1[i]=arr1[i-1]*arrayA[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            arr2[i]=arr2[i+1]*arrayA[i];
        }
        vector<int> ret(n,1);
        for(int i=0;i<n;i++)
        {
            if(i-1>=0)ret[i]*=arr1[i-1];
            if(i+1<n)ret[i]*=arr2[i+1];
        }
        return ret;
    }   
};