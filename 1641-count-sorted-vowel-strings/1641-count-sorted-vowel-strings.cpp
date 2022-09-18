class Solution {
public:
    int countVowelStrings(int n) {
        
        vector<int>dp(n+1);     
        dp[0] = 1;
        for(int j = 0; j < 5; ++j){
            for(int i = 1; i <= n; ++i){
                dp[i] += dp[i-1];
            }
        }
        return dp[n];
    }
};