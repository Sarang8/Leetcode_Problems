class Solution {
public:
//     int dp[1002][1002];
      int mod=1e9+7;
      int dp[1001][1001] = {};
    
//     int solve(int n, int k){
        
//         if(k==0) return 1;
//         if(n==0 or k<0) return 0;
        
//         if(dp[n][k]==0){
//           for(int i=0; i<=min(n-1,k); i++){
//              dp[n][k] = (dp[n][k]%mod + solve(n-1, k-i)%mod)%mod;
//             }
//         }
        
//         return dp[n][k];
//     }
    
    
    
    int kInversePairs(int n, int k) {
        //if(k==0) return 1;
         int dp[1001][1001] = { 1 };
        
        for(int i=1; i<n+1; ++i){
            for(int j=0; j<k+1; ++j){
                for(int p=0; p<=min(i-1,j); ++p){
                    dp[i][j] = (dp[i][j] + dp[i-1][j-p])%1000000007;
                } 
            }
        }
        return dp[n][k];
    }  
};










// class Solution {
// public:
//     int dp[1001][1001] = {};
//     int kInversePairs(int n, int k) {
//         int dp[1001][1001] = { 1 };
//         for (int N = 1; N <= n; N++)
//             for (int K = 0; K <= k; K++)
//                 for (int i = 0; i <= min(K, N - 1); ++i) 
//                     dp[N][K] = (dp[N][K] + dp[N - 1][K - i]) % 1000000007;
//         return dp[n][k];
// }
// };