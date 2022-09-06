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
    
    int solve(TreeNode* root){
        
        if(root==NULL){
            return 0;
        }
        
        if(root->left==NULL && root->right==NULL){
            if(root->val==1){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        int leftSubTree = solve(root->left);
        int rightSubTree = solve(root->right);
        
        if(leftSubTree==0){
            root->left = NULL;
        }
        
        if(rightSubTree==0){
            root->right=NULL;
        }
        
        return leftSubTree + rightSubTree + (root->val==1 ? 1 : 0);
        
    }
    
    
    //COUNT NO. OF ONES FROM RIGHT & LEFT
    TreeNode* pruneTree(TreeNode* root) {
        
        if(solve(root)==0){
            return NULL;
        }
        return root;
    }
};