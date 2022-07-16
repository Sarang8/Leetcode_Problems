/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void MakeParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent){
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            
            if(node->left){
                q.push(node->left);
                parent[node->left] = node;
            }
            
            if(node->right){
                q.push(node->right);
                parent[node->right] = node;
            }   
        }  
    }
    
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*>parent;
        MakeParent(root, parent);
        
        unordered_map<TreeNode*, bool>vis;
        queue<TreeNode*>q;
        
        q.push(target);
        vis[target]=true;
        int CurrDist=0;
        
        while(!q.empty()){
           
            int size=q.size();
            
            if(CurrDist==k) break;
            CurrDist++;
            
            for(int i=0; i<size; i++){
                
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left && vis[node->left]==false){
                    q.push(node->left);
                    vis[node->left]=true;
                }
                
                if(node->right && vis[node->right]==false){
                    q.push(node->right);
                    vis[node->right]=true;
                }
                
                if(parent[node] && vis[parent[node]]==false){
                    q.push(parent[node]);
                    vis[parent[node]]=true;
                }  
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            ans.push_back(node->val); 
        }
        
        
        return ans;
        
    }
};