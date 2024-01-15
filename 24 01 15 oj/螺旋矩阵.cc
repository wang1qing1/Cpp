class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int i=0;
        int j=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<bool>> vv(n,vector<bool>(m));
        for(int t=0;t<(n+1)/2;t++)
        {
            while(j<m&&vv[i][j]!=true)
            {
                ret.push_back(matrix[i][j]);
                vv[i][j]=true;
                j++;
            }
            j--;
            i++;
            while(i<n&&vv[i][j]!=true)
            {
                ret.push_back(matrix[i][j]);
                vv[i][j]=true;
                i++;
            }
            i--;
            j--;
            while(j>=0&&vv[i][j]!=true)
            {
                ret.push_back(matrix[i][j]);
                vv[i][j]=true;
                j--;
            }
            j++;
            i--;
            while(i>=0&&vv[i][j]!=true)
            {
                ret.push_back(matrix[i][j]);
                vv[i][j]=true;
                i--;
            }
            i++;
            j++;
        }
        return ret;
    }
};