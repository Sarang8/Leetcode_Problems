class Solution {
public:
    int solve(int ind, vector<int>&nums, vector<int>&dp){
        if(ind>=nums.size()){
            return 0;
        }    
        
        if(dp[ind]!=-1) return dp[ind];
        
        int t1 = nums[ind] + solve(ind+2, nums, dp);
        int t2 = solve(ind+1, nums, dp);
        
        return dp[ind]=max(t1, t2);
        
    }
    
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solve(0, nums, dp);
        
    }
};