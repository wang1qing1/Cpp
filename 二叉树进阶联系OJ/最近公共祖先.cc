class Solution {
public:
    bool find_path(TreeNode*root,TreeNode*node,stack<TreeNode*>& st)
    {
        if(root==nullptr)
        {  
            return false;
        }
        st.push(root);
        if(root==node)
        {
            return true;
        }
        else
        {
             if(find_path(root->left,node,st)||find_path(root->right,node,st))
             {
                return true;
             }
             else
             {
                 st.pop();
                 return false;
             }
             
        }
       
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        stack<TreeNode*> stp;
        stack<TreeNode*> stq;
        find_path(root,p,stp);
        find_path(root,q,stq);

        while(stp.size()!=stq.size())
        {
            if(stp.size()>stq.size())
            {
                stp.pop();
            }
            else{
                stq.pop();
            }
        }
        while(stp.top()!=stq.top())
        {
            stp.pop();
            stq.pop();
        }
        return stp.top();


    }
};

class Solution {
public:
    bool inTree(TreeNode*root,TreeNode*node)
    {
        if(root==nullptr)
        {
            return false;
        }

        if(root==node||inTree(root->left,node)||inTree(root->right,node))
        {
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==root||q==root)
        {
            return root;
        }

        if(inTree(root->left,q)&&inTree(root->left,p))
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(inTree(root->right,q)&&inTree(root->right,p))
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        else
        {
            return root;
        }
    }
};

