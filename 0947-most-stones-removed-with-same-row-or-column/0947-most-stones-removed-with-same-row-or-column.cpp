class Solution {
public:
    
    
    vector<int>parent;
    
   
    
    int findPar(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=findPar(parent[x]);
    }
    
    bool unin(int x, int y){
        int u=findPar(x);
        int v=findPar(y);
        
        if(u==v){
            return false;
        }
        
        parent[u]=v;
        return true;
        
    }
    
    
    
    int removeStones(vector<vector<int>>& stones) {
        
        int n=stones.size();
        int cnt=0;
        
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                if(stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1]){
                    if(unin(i, j)){
                        cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
};