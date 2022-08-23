class Solution {
public:
    int solve(string &s, string &p, int i, int j, vector<vector<int>>&dp){
        
        if(i<0 or j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        if(s[i]==p[j]){
            dp[i][j] = 1+solve(s, p, i-1, j-1, dp);
        }
        else{
            
            dp[i][j] = max(solve(s, p, i-1,j, dp), solve(s, p, i, j-1, dp));
        }
        
        
       return dp[i][j]; 
        
    }
    
    
    
    
    int minDistance(string word1, string word2) {
        
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        
        
        int LCSlength = solve(word1, word2, n-1, m-1, dp);
	    int deletion = n - LCSlength;
	    int insertion = m -LCSlength;
	    return deletion+insertion;
        
        //return solve(word1, word2, n-1, m-1, dp);
        
    }
};