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
    unordered_map<int,int>mp;
    
    void solve(TreeNode* root){
        
        if(root==NULL){
            return ;
        }
        
        mp[root->val]++;
        
        if(root->left==NULL && root->right==NULL){
            int odd=0;
            
            for(auto it:mp){
                if(it.second%2 != 0){
                    odd++;
                }
            }
            if(odd<=1){
                ans++;
            }
        }
        
        
        solve(root->left);
        solve(root->right);
        mp[root->val]--;
        
    }
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        solve(root);
        return ans;
    }
};