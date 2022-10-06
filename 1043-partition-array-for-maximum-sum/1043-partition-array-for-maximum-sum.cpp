class Solution {
public:
    
    int solve(int idx, vector<int>&nums, int k, vector<int>&dp){
        
        int n =nums.size();
        if(idx>=nums.size()){
            return 0;
        }
        
        if(dp[idx]!=-1) return dp[idx];
        
        int maxi=INT_MIN;
        int ans = 0, temp=0;
        for(int i=idx;i<min(n, idx+k); i++){
            
            maxi = max(maxi, nums[i]);   
            temp = maxi*(i-idx+1) + solve(i+1, nums, k,dp); 
            ans=max(ans, temp);
        }
        
     return dp[idx]=ans;
        
    }
    
    
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n=arr.size();
        vector<int>dp(n+1, -1);
        return solve(0, arr, k, dp);
        
    }
};