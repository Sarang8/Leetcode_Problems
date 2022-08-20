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
    
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        
        vector<int>adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    //adj[j].push_back(i);
                }
            }
        }
        
        vector<int>visi(n, 0);
        int ans=0;
        for(int i=0; i<n; i++){
            
            if(visi[i]==0){
                ans++;
                dfs(i, adj, visi);
                
            }
            
        }
        
        
        return ans;
    }
};