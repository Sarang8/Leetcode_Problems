#define ll long long 
class Solution {
public:
    int mod=1e9+7;
    int solve(int k, int n, int target, vector<vector<ll>>&dp){
        
        if(target<0) return 0;
        
        if(n==0){
            if(target==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(dp[n][target]!=-1) return dp[n][target];
        
        ll ans=0;
        for(int i=1; i<=k; i++){
            ans = ans + solve(k, n-1, target-i, dp)%mod;
        }
        
        return dp[n][target]=ans%mod;
        
    }
    
    
    
    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<ll>>dp(n+1, vector<ll>(target+1, -1));
        return solve(k, n, target, dp);
        
    }
};