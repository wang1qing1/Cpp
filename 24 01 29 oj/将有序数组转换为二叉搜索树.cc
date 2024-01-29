/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* ToBST(int begin, int end, vector<int>& nums)
    {
        if (begin > end)
        {
            return nullptr;
        }
        int mid = (end - begin) / 2 + begin;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = ToBST(begin, mid - 1, nums);
        root->right = ToBST(mid + 1, end, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return ToBST(0, nums.size() - 1, nums);
    }
};