class Solution {
public:
    int solve(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        
        if(i>j){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans=INT_MIN;
        
        for(int ind=i; ind<=j; ind++){
            
            int cost = nums[i-1]*nums[ind]*nums[j+1] + solve(i, ind-1, nums, dp) + solve(ind+1, j, nums, dp);
            ans = max(ans, cost);
        }
        
        
        return dp[i][j]=ans;
        
    }
    
    
    
    
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>>dp(n+2, vector<int>(n+2,-1));
        
        return solve(1, n, nums, dp);
       
    }
};