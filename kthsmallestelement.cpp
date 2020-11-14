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
    vector<int> temp;
    
    int kthSmallest(TreeNode* root, int k) {
        dfs_inorder(root);
        return temp[k-1];
    }
    
    void dfs_inorder(struct TreeNode* root) {
        if (root == nullptr) return;

        dfs_inorder(root->left);
        //cout << root->val << endl;
        temp.push_back(root->val);
        dfs_inorder(root->right);
    }
};
