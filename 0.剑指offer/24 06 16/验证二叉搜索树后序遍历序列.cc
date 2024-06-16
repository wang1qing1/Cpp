class Solution {
public:
    //二叉搜索树后续遍历特点，左 右 根，天然将数据划分为三部分
    //最右边一个是根
    //中间部分比根大
    //左边部分比跟小
    //同时中间部分和，左边部分又都是两部分子树
    
    bool dfs(vector<int>& postorder,int l,int r,int i)
    {
        if(l>=r)return true;
        int root=postorder[i];
        i--;
        while(i>=l&&postorder[i]>=root)
        {
            i--;
        }
        int next=i;
        while(next>=l)
        {
            if(postorder[next]>=root)return false;
            next--;
        }
        return dfs(postorder,l,next,next)&&dfs(postorder,next+1,r-1,r-1);

    }
    bool verifyTreeOrder(vector<int>& postorder) {
        //左 右 根
        //小 大 等
        int r=postorder.size()-1;
        return dfs(postorder,0,r,r);
    }
};