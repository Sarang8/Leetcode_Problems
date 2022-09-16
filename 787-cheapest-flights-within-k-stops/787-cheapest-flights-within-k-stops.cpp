class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int>dist(n, 1e8);
        dist[src]=0;
        
        for(int i=1; i<=k+1; i++){
            vector<int>temp=dist;
            for(auto it:flights){
                if( dist[it[0]] + it[2] < temp[it[1]]){
                    temp[it[1]] = dist[it[0]] + it[2];
                }
            }
            dist=temp;
        }
        
        if(dist[dst]==1e8){
            return -1;
        }
        return dist[dst];
        
        
    }
};