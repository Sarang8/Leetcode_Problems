class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        vector<pair<int,int>> adj[n];
        
        //creating adjency list
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j){
                    int x = abs(points[i][0] - points[j][0]); 
                    int y = abs(points[i][1] - points[j][1]); 
                 
                    adj[i].push_back({j,x+y});
                    adj[j].push_back({j,x+y});
                }   
            }
        }
        
        
        vector<int>key(n);
        vector<bool>MST(n);
        for(int i=0; i<n; i++){
            key[i]=1e8;
            MST[i]=false;
        }
        
        
        vector<int>parent(n);
        
        //priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        //pq.push({0, 0});//{key, node}.... because we want min kay at top
        key[0]=0;
        parent[0]=-1;
        
        
        for(int i=0; i<n-1; i++){
            //int u = pq.top().second;
            int mini=INT_MAX;
            
            int u;
            for(int v = 0;v<n;v++){
                if(MST[v] == false && key[v] < mini){
                    mini = key[v];
                    u =v;
                }
            }
            
            MST[u] = true;
            //pq.pop();
            
            for(auto it:adj[u]){
                int v = it.first;
                int weight=it.second;
                
                if(MST[v]==false && weight<key[v]){
                    parent[v] = u;
                    //pq.push({weight,v});
                    key[v]=weight;
                } 
            }  
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            //cout<<key[i]<<endl;
            ans+=key[i];
        }
        
       return ans; 
    }
};