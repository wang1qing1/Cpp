class Solution {
public:
    typedef vector<vector<vector<int>>> vvvi;
    vector<int> dfs(string& s,int l,int r,vvvi& dp)
    {
        if(dp[l][r][0]!=-1&&dp[l][r][1]!=-1)return {dp[l][r][0],dp[l][r][1]};
        else
        {
            int tmp0=0;
            int tmp1=0;
            if(l==r)
            {
                tmp1=s[l]=='1'?1:0;
                tmp0=s[l]=='1'?0:1;
            }
            else if(r-l==1)tmp0=tmp1=-1;
            {
                for(int k=l+1;k<r;k+=2)
                {
                    vector<int> vleft=dfs(s,l,k-1,dp);
                    vector<int> vright=dfs(s,k+1,r,dp);
                    if(s[k]=='|')
                    {
                        tmp1+=vleft[1]*vright[0]+vleft[0]*vright[1]+vleft[1]*vright[1];
                        tmp0+=vleft[0]*vright[0];
                    }
                    else if(s[k]=='&')
                    {
                        tmp0+=vleft[1]*vright[0]+vleft[0]*vright[1]+vleft[0]*vright[0];
                        tmp1+=vleft[1]*vright[1];
                    }
                    else
                    {
                        tmp0+=vleft[1]*vright[1]+vleft[0]*vright[0];
                        tmp1+=vleft[1]*vright[0]+vleft[0]*vright[1];
                    }
                }
            }
            dp[l][r]={tmp0,tmp1};

        }
        return dp[l][r]; 
    }
    int countEval(string s, int result) {
        int n=s.size();
        vvvi dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return dfs(s,0,n-1,dp)[result];
    }
};
