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
    
    TreeNode* build(vector<int>& postorder, int posStart, int posEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>&inMap){
        
        
        if(posStart>posEnd or inStart>inEnd){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[posEnd]);
        
        int inRoot = inMap[root->val];
        int numLeft = inRoot - inStart;
        
        root->left = build(postorder, posStart, posStart+numLeft-1, inorder, inStart, inRoot-1, inMap);
        
        root->right = build(postorder, posStart+numLeft, posEnd-1 ,inorder, inRoot+1, inEnd, inMap);
        
        
        
        return root;
    }
    
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        map<int,int>inMap;
        
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        
        
        TreeNode* root = build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap );
        
        return root;
        
        
        
    }
};