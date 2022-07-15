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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL) return 0;
        
        queue<pair<TreeNode*, int>>q;
        int first, last;
        int mx=0;
        
        q.push({root, 0});
        
        while(!q.empty()){
            
            int size = q.size();
            int min=q.front().second;
            
            for(int i=0; i<size;i++){
                auto p = q.front();
                TreeNode* node=p.first;
                long long currInd = p.second - min; 
                q.pop();
                
                if(i==0){
                    first = currInd ;
                }
                if(i==size-1){
                    last = currInd;
                }
                
                if(node->left){
                    q.push({node->left, 2*(currInd)+1});
                }
                
                if(node->right){
                    q.push({node->right, 2*(currInd)+2});
                }   
            }
            
            mx = max(mx, last-first+1);
        }
        return mx;
    }
};