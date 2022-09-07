class Solution {
public:
    
    int solve(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        
        if(i>j){
            return 0;
        }
        
        if(i>=nums.size() or j<0){
            return 1e8;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        
        int choice1 = nums[i] + min(solve(i+2, j, nums,dp), solve(i+1, j-1, nums, dp));
        
        int choice2 = nums[j] + min(solve(i, j-2, nums, dp), solve(i+1, j-1, nums, dp));
        
        return dp[i][j]=max(choice1, choice2);
        
        
    }
    
    
    
    
    bool PredictTheWinner(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return true;
        int total=0;
        
        for(auto it:nums){
            total+=it;
        }
        
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        
        int player1 = solve(0, n-1, nums, dp);
        
        if(total-player1 <= player1){
            return true;
        }
        return false;
        
    }
};