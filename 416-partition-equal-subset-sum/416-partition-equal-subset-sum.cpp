class Solution {
public:
    bool solve(int i,vector<int>& arr, int sum, vector<vector<int>>&dp){
        
        if(sum==0){
            return true;
        }
        if(i<0){
            return false;
        }
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        bool t1=false, t2=false;
        
        if(arr[i]<=sum){
            t1 = solve(i-1, arr, sum-arr[i], dp) or solve(i-1, arr, sum, dp);
        }
        
        t2 = solve(i-1, arr, sum, dp);
        
        return dp[i][sum]=t1 or t2;
        
    }
    
    
    
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        int TotalSum=0;
        
        for(auto it:nums){
            TotalSum+=it;
        }
        if(TotalSum%2 != 0){
            return false;
        }
        
        int reqSum = TotalSum/2;
        vector<vector<int>>dp(n+1, vector<int>(reqSum+1, -1));
        
        return solve(n-1, nums, reqSum, dp);
        
        
        
    }
};