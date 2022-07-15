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
    
    bool solve(TreeNode* lf, TreeNode* rt){
        
        if(lf==NULL or rt==NULL){
            return lf==rt;
        }
        
        if(lf->val!=rt->val) return false;
        
        return solve(lf->right, rt->left) &&
               solve(lf->left, rt->right);
        
    }
    
     
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL){
            return true;
        }
        return solve(root->left, root->right);
    }
};