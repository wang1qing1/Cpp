class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param mat int整型vector<vector<>> 
     * @return int整型vector
     */
    void Func(vector<int>& ret,vector<vector<int>>&mat,int i,int j,int& index)
    {
        int b=ret.size();
        int len=0;
        while(j>=0&&i<mat.size())
        {
            ret.push_back(mat[i][j]);
            i++;
            j--;
            len++;
        }
        if(index%2==1)
        {
            reverse(ret.begin()+b,ret.begin()+b+len);
        }
        index++;
    }
    vector<int> diagonalTraverse(vector<vector<int>>& mat) {
        vector<int> ret;
        int index=1;
        for(int i=0;i<mat[0].size();i++)
        {
            Func(ret,mat,0,i,index);
        }
        for(int i=1;i<mat.size();i++)
        {
            Func(ret,mat,i,mat[0].size()-1,index);
        }
        return ret;
    }
};