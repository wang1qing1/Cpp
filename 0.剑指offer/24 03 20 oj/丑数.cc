class Solution {
public:
    int nthUglyNumber(int n) {
       
        vector<int> ret(n);
        int i=1;
        int p1=0;int p2=0;int p3=0;
        ret[0]=1;
        while(i<n)
        {
            int n1=ret[p1]*2;
            int n2=ret[p2]*3;
            int n3=ret[p3]*5;
            int uglynum=min(n1,min(n2,n3));
            ret[i++]=uglynum;
            if(n1==uglynum)p1++;
            if(n2==uglynum)p2++;
            if(n3==uglynum)p3++;
        }
        return ret[n-1];
    }
};