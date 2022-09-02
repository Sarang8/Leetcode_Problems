class Solution {
public:
    
    void solve(int i, int j, vector<vector<int>>&grid){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0){
            return;
        }
        
        grid[i][j]=0;
        solve(i+1, j, grid);
        solve(i-1, j, grid);
        solve(i, j+1, grid);
        solve(i, j-1, grid);
        
    }
    
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        if(n==1 or m==1){
            return 0;
        }
        
        
        for(int i=0; i<m; i++){
            solve(0, i, grid);
            solve(n-1, i, grid);
        }
        
         for(int i=0; i<n; i++){
            solve(i, 0, grid);
            solve(i, m-1, grid);
        }
        
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
};