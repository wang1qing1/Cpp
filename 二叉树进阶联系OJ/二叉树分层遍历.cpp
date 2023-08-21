class Solution {
public:

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>* vv=new vector<vector<int>>;
        queue<TreeNode*> q;
        if(root) q.push(root);
        int count=1;
        while(!q.empty())
        {
            vector<int>* v=new vector<int>;
            while(count--)
            {
                TreeNode* node=q.front();
                q.pop();
                v->push_back(node->val);
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            count=q.size();
            vv->push_back(*v);
        }
        reverse(vv->begin(),vv->end());
        return *vv;
    }
};