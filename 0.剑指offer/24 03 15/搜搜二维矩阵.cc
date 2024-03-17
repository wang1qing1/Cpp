class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x=matrix.size();
        int y=matrix[0].size();
        int i=0;int j=y-1;
        //从右上角开始查询
        while(i<x&&j>=0)
        {
            if(matrix[i][j]==target)return true;
            else if(matrix[i][j]<target)i++;
            else if(matrix[i][j]>target)j--;
        }
        return false;
    }
};