class Solution {
public: 
    
    int findParent(int node, vector<int>&parent){
        
        if(node==parent[node]){
            return node;
        }
        
        return parent[node]=findParent(parent[node], parent);
    }
    
     void unioN(int u, int v, vector<int>&parent, vector<int>&rank){
        
        if(rank[u] < rank[v]){
            parent[u]=v;
        }
        else if(rank[u] > rank[v]){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        
        vector<int>parent(n+1);
        vector<int>rank(n+1);
        
        for(int i=0; i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        
        
        for(int i=0;i<n;i++){
            int f1 = findParent(edges[i][0], parent);
            int f2 = findParent(edges[i][1], parent);
            
            if(f1!=f2){
                unioN(f1, f2, parent, rank);
            }
            else{
                return {edges[i][0], edges[i][1]};
            }
        }
        
         
        
        
        return {};
        
    }
};