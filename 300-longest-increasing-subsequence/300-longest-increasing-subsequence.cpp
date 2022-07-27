class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        
//USING BINARY SEARCH
        vector<int>temp;
        temp.push_back(nums[0]);
        
        for(int i=1; i<n; i++){
            
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
        
        
        
        
//USING TABULATION CONCEPT
        
//         vector<int>dp(n, 1);
//         int maxi = 1;
        
//         for(int ind=0; ind<n; ind++){
//             for(int prev=0; prev<ind; prev++){
                
//                 if(nums[prev]<nums[ind]){
//                     dp[ind] = max( 1+dp[prev], dp[ind]);
//                 }
                
//                 maxi = max(maxi, dp[ind]);
//             }
//         }
//         return maxi;
        
        
     
        
        
//USING DP 
        
//         int n = nums.size();
        
//         vector<vector<int>>dp(n+1, vector<int>(n+1,0));
            
//         //BASE COND IS ALREADY DECLARED IN INITIALIZATION.....SIVE IT WILL BE 0 FOR INDEX==N
            
//         for(int ind=n-1; ind>=0; ind--){
//             for(int pre_ind=ind-1; pre_ind>=-1; pre_ind--){
                
//                 int NotPick=0,pick=0;
                
//                 NotPick = 0 + dp[ind+1][pre_ind+1];
                
//                 if( pre_ind==-1 or nums[pre_ind]<nums[ind]){
//                     pick = 1 + dp[ind+1][ind+1];
//                 }
                
//                 dp[ind][pre_ind+1] = max(pick, NotPick);
//             }
//         }
        
//         return dp[0][0];
        
    }
};