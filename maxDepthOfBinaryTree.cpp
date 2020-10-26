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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if(root != nullptr){
            depth = getMaxheight(root);
        }
        return depth;
    }
    
    int getMaxheight(TreeNode* node){
        if(node == nullptr)
            return 0;
        
        return 1 + max(getMaxheight(node->left),getMaxheight(node->right));
    }
};