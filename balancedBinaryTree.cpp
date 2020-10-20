#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;



struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isBalanced(TreeNode* root);
int findTreeHeight(TreeNode* root);

int main() {
    
    
    struct TreeNode three = TreeNode(3);
    struct TreeNode nine = TreeNode(9);
    struct TreeNode twenty = TreeNode(20);
    struct TreeNode fifteen = TreeNode(15);
    struct TreeNode seven = TreeNode(7);
    three.left = &nine;
    three.right = &twenty;
    nine.left = nullptr;
    nine.right = nullptr;
    twenty.left = &fifteen;
    twenty.right = &seven;
    fifteen.left = nullptr;
    fifteen.right = nullptr;
    seven.left = nullptr;
    seven.right = nullptr;
    

    /*
    struct TreeNode one = TreeNode(1);
    struct TreeNode two = TreeNode(2);
    struct TreeNode two_2 = TreeNode(2);
    struct TreeNode three = TreeNode(3);
    struct TreeNode three_2 = TreeNode(3);
    struct TreeNode four = TreeNode(4);
    struct TreeNode four_2 = TreeNode(4);
    one.left = &two;
    one.right = &two_2;
    two.left = &three;
    two.right = &three_2;
    two_2.left = nullptr;
    two_2.right = nullptr;
    three.left = &four;
    three.right = &four_2;
    three_2.left = nullptr;
    three_2.right = nullptr;
    four.left = nullptr;
    four.right = nullptr;
    */


    bool result = isBalanced(&three);

    if (result)
        cout << "It is a balanced tree." << endl;
    else
        cout << "It is not a balanced tree." << endl;

    return 0;
}



bool isBalanced(TreeNode *root) {
    
    if (root == nullptr) {
        return true;
    }  
    else {
        isBalanced(root->left);
        isBalanced(root->right);
        int leftTreeHeight = findTreeHeight(root->left);
        int rightTreeHeight = findTreeHeight(root->right);
        if (abs(leftTreeHeight - rightTreeHeight) <= 1)
            return true;
        
        return false;
    }
}



int findTreeHeight(TreeNode* root) {

    if (root == nullptr)
        return 0;

    return 1 + max(findTreeHeight(root->left), findTreeHeight(root->right));
}


