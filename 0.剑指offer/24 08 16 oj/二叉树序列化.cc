/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string ret="[";
        while(!q.empty())
        {
            TreeNode* node=q.front();q.pop();
            if(node)
            {
                q.push(node->left);
                q.push(node->right);
                ret+=to_string(node->val);
            }
            else
            {
                ret+="null";
            }
            ret+=",";
        }
        ret.pop_back();
        ret+="]";
        return ret;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<int> arr;
        string str(data.begin()+1,data.end()-1);
        int begin=0;
        int cur=0;
        while(cur<str.size())
        {
            if(str[cur]==',')
            {
                string tmp(str.begin()+begin,str.begin()+cur);
                if(tmp=="null")tmp="11111";
                int val=stoi(tmp);
                arr.push(val);
                begin=cur+1;
            }
            cur++;           
        }
        string tmp(str.begin()+begin,str.begin()+cur);
        if(tmp=="null")tmp="11111";
        int val=stoi(tmp);
        arr.push(val);
        TreeNode* root;
        queue<TreeNode**> q;
        q.push(&root);

        while(!arr.empty())
        {
            TreeNode** pnode=q.front();q.pop();
            val=arr.front();arr.pop();
            if(val==11111)
            {
                (*pnode)=nullptr;
            }
            else
            {
                (*pnode)=new TreeNode(val);
                q.push(&(*pnode)->left);
                q.push(&(*pnode)->right);
            }   
        }
        return root; 
    }
      
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));