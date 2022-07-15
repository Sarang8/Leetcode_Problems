class Solution {
public:
    
    void solve(vector<vector<int>>& grid, int i, int j, int &area, vector<vector<int>> &vis){
        
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]==0 or vis[i][j]==1){
            return;
        }
        
        vis[i][j]=1;
        area+=1;
        
        solve(grid, i+1, j, area,vis);
        solve(grid, i-1, j, area,vis);
        solve(grid, i, j+1, area,vis);
        solve(grid, i, j-1, area,vis);
           
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col,0));
        
        int mx=0;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                
                int area = 0;
                
                if(grid[i][j]==1){
                    solve(grid, i, j, area, vis);
                }
                
                mx=max(mx, area);
                
            }
        }
        
        
        return mx;
    }
};