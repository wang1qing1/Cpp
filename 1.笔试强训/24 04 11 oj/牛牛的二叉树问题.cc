
  struct TreeNode {
 	int val;
 	struct TreeNode left;
 	struct TreeNode right;
 	TreeNode(int x)  val(x), left(nullptr), right(nullptr) {}
  };
 
class Solution {
public
    
      代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     
      
      @param root TreeNode类 
      @param target double浮点型 
      @param m int整型 
      @return int整型vector
     
     double tar;
     typedef pairint,int PII;
    void dfs(TreeNode root,vectorPII& path)
    {
        if(root==nullptr)return;
        path.push_back({abs((root-val)1.0-tar),root-val});
        dfs(root-left,path);
        dfs(root-right,path);
    }
    vectorint findClosestElements(TreeNode root, double target, int m) {
        vectorpairint,int path;
        tar=target;
        dfs(root,path);
        sort(path.begin(),path.end(),[&](PII e1,PII e2){
            return e1.firste2.first;
        });
        vectorint ret;
        for(int i=0;im;i++)
        {   
            auto [a,b]=path[i];
            ret.push_back(b);
        }
        sort(ret.begin(),ret.end());
        return ret;
    }
};