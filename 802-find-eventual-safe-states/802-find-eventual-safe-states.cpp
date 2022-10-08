class Solution {
public:
    
    bool detectCycle(int node, vector<int>&vis, vector<int>&DFSvis, vector<int>&check, vector<int>adj[]){
        
        vis[node]=1;
        DFSvis[node]=1;
        
        for(auto it:adj[node]){
            
            if(vis[it]==0){
                if(detectCycle(it, vis, DFSvis, check, adj)){
                    check[node]=0;
                    return true;
                }
            }
            else{
                if(DFSvis[it]==1){
                    check[node]=0;
                    return true;
                }
            }
        }
        
        DFSvis[node]=0;
        check[node]=1;
        return false; 
    }
    
    
    
    
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>adj[n];
        // vector<int>outdegree(n, 0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<int>vis(n, 0);
        vector<int>DFSvis(n, 0);
        vector<int>check(n, 0);
        
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                detectCycle(i, vis, DFSvis, check, adj);
            }
        }
        
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};