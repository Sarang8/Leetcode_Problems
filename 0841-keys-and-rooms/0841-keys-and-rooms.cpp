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
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        vector<int>adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }   
        }
        
        vector<int>visi(n,0);
        int cnt=0;
        
        for(int i=0;i<n;i++){
            if(visi[i]==0){
                cnt++;
                dfs(i, adj, visi);
            }    
        }
        
        if(cnt>1) return false;
        return true;
    }
};