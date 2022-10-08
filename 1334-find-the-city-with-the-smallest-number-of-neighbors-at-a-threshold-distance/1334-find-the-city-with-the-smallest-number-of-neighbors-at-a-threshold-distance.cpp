class Solution {
public:
    
    void dikjistra(int src, int n, vector<pair<int,int>>&ans, vector<pair<int,int>>adj[], int distanceThreshold){
        
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(n, 1e8);
        pq.push({0, src});
        dist[src]=0;
        
        while(!pq.empty()){
            
            int u=pq.top().second;
            pq.pop();
            
            for(auto it:adj[u]){
                int v=it.first;
                if(dist[v] > dist[u]+it.second){
                    dist[v]=dist[u]+it.second;
                    pq.push({dist[v], v});
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i!=src && dist[i]<=distanceThreshold){
                cnt++;
            }
        }
        
        ans.push_back({cnt, src});
        
    }
    
    static bool compr(pair<int,int>&a, pair<int,int>&b){
        
        if(a.first<b.first){
            return true;
        }
        if(a.first==b.first){
            return a.second>b.second;
        }
        return false;
    }
    
    
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int,int>>adj[n];
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        vector<pair<int,int>>ans;
        
        for(int i=0;i<n;i++){
            dikjistra(i, n, ans, adj, distanceThreshold);
        }
        
        sort(ans.begin(), ans.end(), compr);
        return ans[0].second;
    }
};