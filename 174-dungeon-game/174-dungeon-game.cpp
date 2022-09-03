class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>>& d, vector<vector<int>>&dp){
        
        if(i>=d.size() or j>=d[0].size()){
            return 1e8;
        }
        
        if(i==d.size()-1 && j==d[0].size()-1){
            return d[i][j]<=0 ? abs(d[i][j])+1 : 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int op1 = solve(i+1, j, d, dp);
        int op2 = solve(i, j+1, d, dp);
        
        int  ans = min(op1, op2) - d[i][j];
        
        return dp[i][j]=ans<=0 ? 1 : ans;
        
        
    }
    
    
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        
        return solve(0, 0, dungeon, dp);  
        
    }
};