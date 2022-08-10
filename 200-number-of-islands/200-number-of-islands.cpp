class Solution {
public:
    
    void dfs(int i, int j, vector<vector<char>>& grid){
        
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]=='0'){
            return;
        }
        
        grid[i][j]='0';
        
        dfs(i+1, j, grid);
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i, j-1, grid);
    }
    
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i, j, grid);
                }
                
            }
        }
        return ans; 
    }
};