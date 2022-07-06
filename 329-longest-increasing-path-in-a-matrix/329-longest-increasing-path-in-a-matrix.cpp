class Solution {
public:
    vector<int>dx={0, 0, 1, -1};
    vector<int>dy = {1, -1, 0, 0};
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>&dp, int i, int j){
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        
        int mx=1;
        
        for(int k=0; k<4; k++){
            
            int  x = i+dx[k];
            int y = j+dy[k];
            
            if(x<0 or x>=matrix.size() or y<0 or y>=matrix[0].size() or matrix[i][j]>=matrix[x][y]){
                continue;
            }
            else{
                mx = max(mx, 1+dfs(matrix,dp, x, y) );
            }  
        }
        return dp[i][j] = mx;        
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>>dp(n, vector<int>(m,0));
        int ans=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans=max(ans,dfs(matrix, dp, i, j));  
            }
        }
        return ans;        
        
    }
};