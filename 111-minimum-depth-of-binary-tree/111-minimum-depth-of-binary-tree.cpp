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
    int height(TreeNode* root){
        
        if(root==NULL) return 0;
        
        
        if(root->right==NULL){
            return 1 + height(root->left);
        }
        
        if(root->left==NULL){
           return 1 + height(root->right);
        }
        
        return 1 + min(height(root->left), height(root->right));        
    }
    
    
    int minDepth(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        int mini=INT_MAX;
        return height(root);
        
        
        
    }
};