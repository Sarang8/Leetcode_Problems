class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1));
        
        for(int i=0; i<n+1; i++){
            dp[i][0] = i;
        }
        
        for(int j=0; j<m+1; j++){
            dp[0][j]=j;
        }
        
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = 0 + dp[i-1][j-1];
                }
                else{
                    
                    //FOR INSERT
                    int insert = 1+dp[i][j-1];
                    
                    //FOR DELETE
                    int delet = 1+dp[i-1][j];
                    
                    //FOR REPACE
                    int replce = 1+dp[i-1][j-1];
                    
                    //ALSO SHORT CUT
                    //dp[i][j] = 1+ min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                    
                    dp[i][j] = min(insert, min(delet, replce));
                }
                
            }
        }
        
        return dp[n][m];   
    }
};