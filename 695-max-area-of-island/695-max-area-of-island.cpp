class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& area) {
        
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]!=1){
            return;
        }
        
        if(grid[i][j]==1){
            area = area+1;
        }
        
        grid[i][j]=0;
        
        dfs(grid, i - 1, j, area);
        dfs(grid, i + 1, j, area);
        dfs(grid, i , j+1, area);
        dfs(grid, i , j-1, area);
    }
        
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
            int area = 0;
            if (grid[i][j] == 1) {
                dfs(grid, i, j, area);
            } 
            ans = max(ans, area);
          }
        }
        return ans; 
    }
};