class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<pair<int,int>> vvindex;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(matrix[i][j]==0)vvindex.push_back({i,j});

        for(auto [a,b]:vvindex)
        {
            for(int i=0;i<m;i++)matrix[a][i]=0;
            for(int i=0;i<n;i++)matrix[i][b]=0;
        }
        
    }
};

