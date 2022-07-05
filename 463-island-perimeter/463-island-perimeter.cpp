class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int i, int j, int &ans, vector<vector<bool>>&vis){
        
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]==0){
            ans = ans+1;
            return;
        }
        
        if(vis[i][j]==true)    //if the cell is visited return  
       {
         return;
       }
 
       vis[i][j]=true;
        
        
        dfs(grid, i+1, j,ans, vis);
        dfs(grid, i-1, j,ans,vis);
        dfs(grid, i, j-1,ans,vis);
        dfs(grid, i, j+1,ans,vis); 
    }
    
    
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        vector<vector<bool>>vis(row, vector<bool>(col,false));
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                
                if(grid[i][j]==1 and vis[i][j]==false){
                    dfs(grid, i, j, ans, vis);
                    break;
                }
               
            }
        }
        
        return ans;
        
        
    }
};