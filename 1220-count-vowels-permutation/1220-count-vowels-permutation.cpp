class Solution {
public:
    int countVowelPermutation(int n) {
        
        long long dp[5][n+1];
        int mod=1e9+7;
        
        dp[0][1]=dp[1][1]=dp[2][1]=dp[3][1]=dp[4][1]=1;
        
        long long ans=0;
        
        for(int i=2; i<n+1; i++){
            
            dp[0][i] = dp[1][i-1];
            dp[1][i] = (dp[0][i-1]+dp[2][i-1])%mod;
            dp[2][i] = (dp[0][i-1]+dp[1][i-1]+dp[3][i-1]+dp[4][i-1])%mod;
            dp[3][i] = (dp[2][i-1]+dp[4][i-1])%mod;
            dp[4][i] = (dp[0][i-1])%mod;  
        }
        
        for(int i=0; i<5; i++){
            ans = (ans+dp[i][n])%mod;
        }
        return ans;
    }
};