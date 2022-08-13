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
    int ans=0;
    void solve(TreeNode* root, int targetSum, long long currSum){
        
        if(root==NULL) return ;
        
        currSum += root->val;
        
        if(currSum==targetSum){
            ans++;
        }
        
        solve(root->left, targetSum, currSum);
        solve(root->right, targetSum, currSum);
    }
    
    
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL) return 0;
        
       
        long long currSum=0;
        
        solve(root, targetSum, currSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
       
        return ans;
    }
};