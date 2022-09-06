class Solution {
public:
    int mod=1e9+7;
    
    int  solve(int i, int j, vector<vector<int>>&matrix, vector<vector<int>>&dp){
         
        int n=matrix.size();
        int m=matrix[0].size();
        
        if(i<0 or j<0 or i>=n or j>=m){
            return 0; 
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int t1=1;
        
        if(i+1<n && matrix[i+1][j]>matrix[i][j]){
            t1 = (1+solve(i+1, j, matrix, dp))%mod;
            
        }
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j]){
            t1 =  t1 + solve(i-1, j, matrix, dp)%mod;
        }
        if(j+1<m && matrix[i][j+1]>matrix[i][j]){
            t1 =  t1 + solve(i, j+1, matrix, dp)%mod;
        }
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j]){
            t1 =  t1 + solve(i, j-1, matrix, dp)%mod;
        }
        
        return dp[i][j]=t1%mod;
    }
    
    
    
    int countPaths(vector<vector<int>>& grid) {
            
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1, -1));
        
        long long ans=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans= (ans%mod + solve(i, j, grid, dp)%mod)%mod;
            }
        }
        return ans;
    }
};