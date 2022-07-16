class Solution {
public:
    
   long long dp[55][55][55];
    int mod=1e9+7;
    
    int solve(int m, int n, int maxMove, int i, int j){
        
        if(maxMove<0){
            return 0;
        }
        
        if(i<0 or j<0 or i>=m or j>=n ){
            return 1; 
        } 
        
        if(dp[maxMove][i][j]!=-1){
            return dp[maxMove][i][j];
        }
        
        long long t1=solve(m,n, maxMove-1, i+1, j)%mod;
        long long t2=solve(m,n, maxMove-1, i-1, j)%mod;
        long long  t3=solve(m,n, maxMove-1, i, j+1)%mod;
        long long t4=solve(m,n, maxMove-1, i, j-1)%mod;
        
        dp[maxMove][i][j] = (t1%mod+t2%mod+t3%mod+t4%mod)%mod;
        return dp[maxMove][i][j];
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp, -1, sizeof(dp));
        dp[maxMove][m][n]=solve(m,n, maxMove, startRow,startColumn);
        return dp[maxMove][m][n];
        
    }
};