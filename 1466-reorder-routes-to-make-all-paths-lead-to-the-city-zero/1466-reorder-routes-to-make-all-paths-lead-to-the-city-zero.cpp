class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<int>adj[n], back[n];
        for(int i=0; i<connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            back[connections[i][1]].push_back(connections[i][0]);
        }
        
        queue<int>q;
        vector<int>vis(n, 0);
        q.push(0);
        
        int count=0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node]=1;
            
            for(auto it:adj[node]){
                if(vis[it]==0){
                    count++;
                    q.push(it);
                }
            }
            
            for(auto it:back[node]){
                if(vis[it]==0){
                    q.push(it);
                }
            }  
        }
        
        return count;
        
        
        
        
    }
};