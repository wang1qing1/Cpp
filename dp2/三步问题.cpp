class Solution {
public:
    int waysToStep(int n) {
        int a1=1;
        int a2=2;
        int a3=4;
        int an=0;

        const int MOD=1E9 +7;

        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(n==3)
            return 4;

        for(int i=4;i<=n;i++)
        {
            an=((a1+a2)%MOD+a3)%MOD;
            a1=a2;
            a2=a3;
            a3=an;
        }
        return an;

    }
};