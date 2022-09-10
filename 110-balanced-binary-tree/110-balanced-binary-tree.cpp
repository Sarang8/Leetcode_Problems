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
        
        if(root==NULL) return 0;
        
        
        
        int lt=solve(root->left);
        if(lt==-1){
            return -1;
        }
        
        int rt=solve(root->right);
        if(rt==-1){
            return -1;
        }
        
        if(abs(lt-rt) > 1){
            return -1;
        }
        
        return 1+max(lt, rt);
    }
    
    
    
    bool isBalanced(TreeNode* root) {
        
        if(root==NULL) return true;
        
        if(solve(root)==-1){
            return false;
        }
        return true;
        
    }
};