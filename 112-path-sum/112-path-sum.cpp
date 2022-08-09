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
    bool solve(TreeNode* root, int targetSum, int sum){
        
        sum+=root->val;
        
        if(sum==targetSum && root->left==NULL && root->right==NULL){
            return true;
        }
        
        
        bool t1=0, t2=0;
        if(root->left){
           t1=solve(root->left, targetSum, sum); 
        }
        if(root->right){
           t2=solve(root->right, targetSum, sum); 
        }
        
        return  t1 or t2; 
        
        
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL) return false;
        
        return solve(root, targetSum, 0);
        
        
        
    }
};