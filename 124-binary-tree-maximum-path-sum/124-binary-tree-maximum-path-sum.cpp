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
    
    int solve(TreeNode* root, int &maxi){
        
        if(root==NULL) return 0;
        
        int lefti = max(0,solve(root->left, maxi));
        int righti = max(0, solve(root->right, maxi));
        
        maxi=max(maxi, root->val+lefti+righti);
                       
        return root->val+max(lefti, righti);
    
    }
    
    
    
    int maxPathSum(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        int maxi=INT_MIN;
        solve(root,maxi);
        
        return maxi;
        
    }
};