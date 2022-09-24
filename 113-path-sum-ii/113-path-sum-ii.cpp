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
    
    void solve(TreeNode* root, int currSum, int target, vector<int>&ds, vector<vector<int>>&ans){
        
        if(root==NULL){
            return;
        }
        
        currSum=currSum+root->val;
        ds.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL){
            if(target==currSum){
                ans.push_back(ds); 
              
            }
            
        }
        
        
        solve(root->left, currSum,target, ds, ans);
        solve(root->right, currSum, target, ds, ans);
        
        currSum-=root->val;
        //cout<<currSum<<endl;
        ds.pop_back();        
    }
    
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }    
        vector<int>ds;
        int currSum=0;
        solve(root, 0,targetSum, ds, ans);
        
        return ans;
    }
};