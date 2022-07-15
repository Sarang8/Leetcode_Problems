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
    
//     int height(TreeNode* root, int &maxi){
        
//         if(root==NULL){
//             return 0;
//         }
        
//         //We USED MAX(0, HEIGHT) BECAUSE IF IN CASE WE GET NEGATIVE SUM THEN WE WILL NOT CONSIDER IT AND MAKE IT AS 0.
//         int lh = max(0,height(root->left, maxi));
//         int rh = max(0,height(root->right, maxi));
        
//         maxi = max(maxi, root->val+lh+rh);
        
//         return (root->val) + max(lh,rh);
//         //HERE MAX(LH,RH) IS NECEESARY TO KNOW WHEHER U TAKE LRFT PATH OR RIGHT PATH
//     }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    int solve(TreeNode* root, int &maxi){
        
        if(root==NULL){
            return 0;
        }
        
        
        int left = max(0,solve(root->left, maxi));
        int right = max(0, solve(root->right,maxi));
        
        maxi = max(maxi, (root->val + left+right));
        
        return root->val+max(left,right);
    
    }    
    
    int maxPathSum(TreeNode* root) {
        
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
        
    }
};