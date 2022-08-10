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
    TreeNode* help(vector<int>&nums, int left, int right){
        
        
        if (left > right) return NULL;
        
        int mid = left + (right-left)/2;
        
        TreeNode* root=new TreeNode(nums[mid]);
        
        root->left = help(nums, left, mid-1);
        root->right = help(nums, mid+1, right);
        
        return root;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==0) return NULL;
        if(n==1) return new TreeNode(nums[0]);
                
        return help(nums, 0, n-1);
        
    }
};