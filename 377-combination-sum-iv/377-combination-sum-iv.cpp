class Solution {
public:
    
    int dp[201][1001];
    
    int solve(int ind, vector<int>& nums, int target){
        
        if(target==0){
            return 1;
        }
    
        if(target<0){
            return 0;
        }
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        int ans=0;        
        for(int i=ind; i<nums.size(); i++){
            if(target>=nums[i])
               ans += solve(ind, nums, target-nums[i]);
        }
        
        return dp[ind][target]=ans;
        
    }
    
    
    
    int combinationSum4(vector<int>& nums, int target) {
        
        int sum=0;
        memset(dp,-1,sizeof(dp));
        return solve(0,nums, target);
     //   return ans.size();
    }
};