class Solution {
public:
    bool isMatch(string s,string p) {
        
        int n=p.size();
        int m=s.size();
        
        vector<vector<bool>>dp(n+1, vector<bool>(m+1));
         
        dp[0][0]=true;
        
        for(int j=1; j<m+1; j++){
            dp[0][j] = false;            
        }
        
        for(int i=1; i<n+1; i++){
            bool fl = true;
            
            for(int x=1; x<=i; x++){
                if(p[x-1]!='*'){
                    fl = false;
                    break;
                }
            }  
            dp[i][0]=fl; 
        }
        
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                  
                if(p[i-1]==s[j-1] or p[i-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                
                else if(p[i-1]=='*'){
                    dp[i][j] = (dp[i-1][j] | dp[i][j-1]);
                }
                else{
                    dp[i][j] = false;
                }

                }
            }
         
        return dp[n][m];
    }
};