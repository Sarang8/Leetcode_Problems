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
    
    int leftMost(TreeNode* root){
        int h=0;
        while(root){
            root=root->left;
            h++;
        }
        return h;
    }
    
    int rightMost(TreeNode* root){
        int h=0;
        while(root){
            root=root->right;
            h++;
        }
        return h;
    }
    
    
    
    int countNodes(TreeNode* root) {
        
        if(root==NULL) return 0;
        
        int l = leftMost(root);
        int r = rightMost(root);
        
        if(l==r){
            return  (1<<l) - 1;   // --->>  pow(2, l)-1;
        }
        
        return 1 + countNodes(root->left)+countNodes(root->right); 
    }
};