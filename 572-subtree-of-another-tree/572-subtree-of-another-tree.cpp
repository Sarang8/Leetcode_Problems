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
    bool solve(TreeNode* root, TreeNode* subRoot){
        
        if(root==NULL or subRoot==NULL){
            return root==subRoot;
        }
        
        return root->val==subRoot->val && solve(root->left, subRoot->left) && solve(root->right, subRoot->right);
        
    }
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root==NULL or subRoot==NULL){
            return root==subRoot;
        }
        
        return solve(root, subRoot) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
        
    }
};