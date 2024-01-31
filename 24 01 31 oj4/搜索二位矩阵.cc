class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=0;//列
        int row=0;//行
        int n=matrix.size();
        int m=matrix[0].size();
        while(row<n&&col<m)
        {
            if(target==matrix[row][col])return true;
            if(target>matrix[row][m-1])row++;
            else if(target<=matrix[row][m-1])col++;
        }
        return false;
    }
};