class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sum.resize(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        for(int i=1;i<matrix.size()+1;i++)
        {
            for(int j=1;j<matrix[0].size()+1;j++)
            {
                sum[i][j]=sum[i-1][j]+sum[i][j-1]+matrix[i-1][j-1]-sum[i-1][j-1];
                cout<<sum[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
         row1++;
         col1++;
         col2++;
         row2++;
        return sum[row2][col2]-sum[row1-1][col2]-sum[row2][col1-1]+sum[row1-1][col1-1];
    }
    vector<vector<int>> sum;
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */