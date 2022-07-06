class Solution {
public:
    
    void toposort(int node,vector<pair<int,int>>adj[], stack<int>&st,  vector<int>&vis){
        
        vis[node]=1; 
        for(auto it : adj[node]){
            if(vis[it.first]==0)
                toposort(it.first, adj, st, vis);
        }
        st.push(node);   
    }
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>>adj[n+1];
        
        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        vector<int>vis(n+1,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        //stack<int>st;
        
//         for(int i=1; i<=n; i++){
//             if(vis[i]==0){
//                 toposort(i, adj, st, vis);
//             }
//         }
        
        
        
        vector<int>dist(n+1, 0);
        for(int i=0; i<=n; i++){
            dist[i]=1e9;
        }
        
        dist[k] = 0;
        pq.push({k, 0});
        
        
        
//          while(!st.empty()){
//                 int node=st.top();
//                 st.pop();

//              if(dist[node]!=1e9){
//                 for(auto it:adj[node]){

//                     int nextNode=it.first;
//                     int nextDist=it.second;

//                     if(dist[node]+nextDist < dist[nextNode]){
//                         dist[nextNode] = dist[node]+nextDist;
                        
//                     }
//                 }   
//              }
            
//         }
        
        

                while(!pq.empty()){
                    auto p=pq.top();
                    int node=p.first;
                    pq.pop();
                    
                    for(auto it:adj[node]){
                        
                        int nextNode=it.first;
                        int nextDist=it.second;
                        
                        if(dist[node]+nextDist < dist[nextNode]){
                            dist[nextNode] = dist[node]+nextDist;
                            pq.push({nextNode, dist[nextNode]});
                        }
                        
                    }  
                }

        
        int ans=INT_MIN;
        for(int i=1; i<=n; i++){
            ans=max(ans, dist[i]);
        }
        
        if(ans==1e9){
            return -1;
        }
        return ans;
        
    }
};