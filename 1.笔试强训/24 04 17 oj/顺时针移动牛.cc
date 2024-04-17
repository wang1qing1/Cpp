class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix int整型vector<vector<>> 
     * @return int整型vector
     */
    // [1, 2, 3] 
    // [4, 5, 6]
    // [7, 8, 9]
    vector<int> printMatrixInSpiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        int count=(matrix.size()+1)/2;
        int top=0;int left=0;int right=matrix[0].size()-1;int down=matrix.size()-1;
        while(count--)
        {
            for(int i=left;i<=right;i++)ret.push_back(matrix[top][i]);
            top++;
            for(int i=top;i<=down;i++)ret.push_back(matrix[i][right]);
            right--;
            for(int i=right;top<=down&&i>=left;i--)ret.push_back(matrix[down][i]);
            down--;
            for(int i=down;left<=right&&i>=top;i--)ret.push_back(matrix[i][left]);
            left++;
        }
        return ret;
    }
};