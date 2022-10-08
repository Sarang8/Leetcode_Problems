class Solution {
public:
    
    void dfs(int node, vector<int>adj[], vector<int>&visi){
        
        visi[node]=1;
        
        for(auto it:adj[node]){
            if(visi[it]==0){
                dfs(it, adj, visi);
            }
        }
        
    }
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int m=connections.size();
        if(m<n-1){
            return -1;
        }
        
        vector<int>adj[n];
        vector<int>visi(n, 0);
        
        for(int i=0;i<m;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        
        int connectedComp=0;
        for(int i=0;i<n;i++){
            if(visi[i]==0){
                connectedComp++;
                dfs(i, adj,visi);  
            }
        }
        
        return connectedComp-1;
        
        
        
    }
};