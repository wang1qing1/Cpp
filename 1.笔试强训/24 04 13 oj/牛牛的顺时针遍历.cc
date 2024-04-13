class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix int整型vector<vector<>> 
     * @return int整型vector
     */


//  [1,  2,  3,  4,  5]
//  [6,  7,  8,  9,  10]
//  [11, 12, 13, 14, 15]
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
      vector<int> ret; 
      int flag=99999;
      int n=matrix.size();
      int m=matrix[0].size();
      int c=(n+1)/2;
      for(int i=0;i<c;i++)
      {
            int index=i;//1
            while(index<m-i)//4
            {
                if(matrix[i][index]!=flag)ret.push_back(matrix[i][index]);
                matrix[i][index]=flag;
                index++;
            }
            index=i+1;//2
            while(index<n-i)//2
            {
                if(matrix[index][m-i-1]!=flag)ret.push_back(matrix[index][m-i-1]);
                matrix[index][m-i-1]=flag;
                index++;
            }
            index=m-i-1-1;//2
            while(index>=i)//1
            {
                if(matrix[n-i-1][index]!=flag)
                    ret.push_back(matrix[n-i-1][index]);
                matrix[n-i-1][index]=flag;
                index--;
            }
            index=n-i-1-1;
            while(index>i)
            {
                if(matrix[index][i]!=flag)ret.push_back(matrix[index][i]);
                matrix[index][i]=flag;
                index--;
            }
      }
      return ret;
    }
};