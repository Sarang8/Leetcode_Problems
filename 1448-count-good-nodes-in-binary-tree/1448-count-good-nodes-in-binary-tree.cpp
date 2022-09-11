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
    void solve(TreeNode* root, int prev){
        
        if(root==NULL){
            return;
        }
        
        if(root->val < prev){
           ans=ans+0;
            //prev=root->val;
            solve(root->left, prev);
            solve(root->right, prev);
        }
        else{
            ans++;
            prev=root->val;
            solve(root->left, prev);
            solve(root->right, prev);
           
        }
        
    }
    
    
    
    int goodNodes(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        solve(root, INT_MIN);
        
        return ans;
    }
};