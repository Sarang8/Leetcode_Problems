class Solution {
public:
    int solve(int i, int j1, int j2, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp){
        
        if(j1<0 or j2<0 or j1>=grid[0].size() or j2>=grid[0].size()){
            return -1e8;
        }
        
        if(i>=grid.size()){
            return 0;
        }
        
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        
        int maxi=INT_MIN;
        
        for(int dj1=-1; dj1<=1; dj1++){
            for(int dj2=-1; dj2<=1; dj2++){
                
                if(j1==j2){
                    maxi=max(maxi, grid[i][j1] + solve(i+1, j1+dj1, j2+dj2, grid, dp));
                }
                else{
                    maxi=max(maxi, grid[i][j1]+grid[i][j2]+ solve(i+1, j1+dj1, j2+dj2, grid, dp));
                }   
            }
        }
    
        return dp[i][j1][j2]=maxi;
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(m+1, vector<int>(m+1, -1)));
        return solve(0, 0, m-1, grid, dp);
        
        
        
        
    }
};