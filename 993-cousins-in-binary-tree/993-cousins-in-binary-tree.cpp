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
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        if(root->val==x && root->val==y) return false;
        
        queue<pair<TreeNode* , TreeNode*>>q;
        
        q.push({root, NULL});
        
        while(!q.empty()){
            
            TreeNode* xParent=NULL;
            TreeNode* yParent=NULL;
            
            int size=q.size();
            
            for(int i=0; i<size; i++){
                
                TreeNode* node=q.front().first;
                TreeNode* parent = q.front().second;
                q.pop();
                
                if(node->val==x){
                    xParent = parent;
                }
                
                else if(node->val==y){
                    yParent=parent;
                }
                
                
                if(node->left) q.push({node->left, node});
                if(node->right) q.push({node->right, node});
                
            }
            
            if( xParent || yParent){
                return xParent && yParent && xParent!=yParent; 
            }
            
            
        }
        
        
        return false;
        
        
    }
};