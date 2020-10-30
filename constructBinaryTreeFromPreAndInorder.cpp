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
    unordered_map<int, int> inorder_node_indexes;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
        size_t preorder_size = preorder.size();
        size_t inorder_size = inorder.size();
        if(preorder_size > 0 && inorder_size > 0){
            for (size_t i = 0; i < inorder_size; i++) {
                inorder_node_indexes[inorder[i]] = i;
            }
            struct TreeNode* parent = new TreeNode(preorder[0]);
            preorder.erase(preorder.begin());
            recursiveCall(preorder, parent);
            return parent;
        }
    
        return nullptr;
    }



void recursiveCall(vector<int>& input, TreeNode* parentNode) {
    if (input.size() >= 1) {
        int inorderParentIdx = inorder_node_indexes[parentNode->val];
        int tempChildIndx;
        vector<int> vector1;
        vector<int> vector2;
        for (size_t i = 0; i < input.size(); i++) {
            tempChildIndx = inorder_node_indexes[input[i]];
            if (tempChildIndx < inorderParentIdx)
                vector1.push_back(input[i]);
            else
                vector2.push_back(input[i]);
        }

        int vector1_size = vector1.size();
        int vector2_size = vector2.size();
        if (vector1_size > 0) {
            parentNode->left = new TreeNode(vector1[0]);
            if (vector1_size > 1) {
                vector1.erase(vector1.begin());
                recursiveCall(vector1, parentNode->left);
            }
        }
        if (vector2_size > 0) {
            parentNode->right = new TreeNode(vector2[0]);
            if (vector2_size > 1) {
                vector2.erase(vector2.begin());
                recursiveCall(vector2, parentNode->right);
            }
        }

    }
}
};