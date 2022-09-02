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
    vector<TreeNode*> allPossibleFBT(int n) {
        
        if(n==1){
            return {new TreeNode(0)};
        }
        
        vector<TreeNode*>ans;
        
        for(int i=2; i<n; i++){
            vector<TreeNode*>leftPossibleTree =  allPossibleFBT(i-1);
            vector<TreeNode*>rightPossibleTree =  allPossibleFBT(n-i);
            
            for(auto lefti : leftPossibleTree){
                for(auto righti : rightPossibleTree){
                    
                    TreeNode* root= new TreeNode(0);
                    root->left = lefti;
                    root->right = righti;
                    ans.push_back(root);
                }
            }
            
            
            
            
        }
        
        
        
        
        return ans;
        
    }
};