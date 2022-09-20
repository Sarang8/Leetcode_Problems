class Solution {
public:
    int solve(int i, int j, vector<int>&nums1, vector<int>&nums2, vector<vector<int>>&dp, int &ans){
        
        if(i<0 or j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(nums1[i]==nums2[j]){
           dp[i][j]=1+solve(i-1, j-1, nums1, nums2, dp, ans);
        }
        else{
            dp[i][j]=0;
        }
        
         solve(i-1, j, nums1, nums2, dp, ans);
         solve(i, j-1, nums1, nums2, dp, ans);
        
        
        ans = max(ans, dp[i][j]);
        return dp[i][j];
        
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        
        int n =nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        int ans=INT_MIN;
        solve(n-1, m-1, nums1, nums2, dp, ans);
        return ans;
        
        
    }
};