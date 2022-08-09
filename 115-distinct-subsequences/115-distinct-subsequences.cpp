class Solution {
public:
//     int dp[1005][1005];
    
//     int solve(string s, string t, int i, int j){
        
//         if(j<0) return 1;
//          if(i<0 and j<0)
//             return 1;
//         if(i<0) return 0;
       
        
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         if(s[i]==t[j]){ 
//             return dp[i][j] = (solve(s,t, i-1, j-1) + solve(s,t,i-1, j)); 
//         }
//         else{
//             return dp[i][j] =  solve(s,t,i-1,j);
//         }        
//     }
    
    
    
    
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
//         memset(dp,-1,sizeof(dp));
        
//         return solve(s, t, n-1, m-1);
        
        vector<vector<double>>dp(n+1, vector<double>(m+1,0));
        
        for(int i=0; i<n+1; i++){
                  dp[i][0]=1;
            }
            for(int j=1; j<m+1; j++){
                dp[0][j]=0;
            }

        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
                
            }
        }
        return (int)dp[n][m];    
    }
};