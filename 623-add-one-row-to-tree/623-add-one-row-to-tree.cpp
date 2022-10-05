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
    void solve(TreeNode* root, int currDepth, int val, int depth){
        
        if(root==NULL){
            return ;
        }
        if(currDepth == depth-1){
            TreeNode *l = root -> left, *r = root -> right;
            root -> left = new TreeNode(val,l,NULL);// original left child becomes child of new node with value v
		    root -> right = new TreeNode(val, NULL, r);// same as above for right child
		    return;
        }
        
        solve(root->left, currDepth+1, val, depth);
        
        solve(root->right, currDepth+1, val, depth);
       
        return ;
    }
    
    
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
     
        if(depth==1){
            TreeNode* curr = new TreeNode(val);
            curr->left = root;
            curr->right=NULL;
            return curr;
        }
        
        solve(root, 1, val, depth);
        
        return root;
        
        
    }
};