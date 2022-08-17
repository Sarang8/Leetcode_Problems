class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp1(n, 1);
        vector<int>dp2(n, 1);
        int ans;

        
        for(int ind=0; ind<n; ind++){
            for(int prev=0; prev<ind; prev++){
                
                if(nums[prev]<nums[ind] && 1+dp1[prev]>dp1[ind]){
                    dp1[ind] = 1 + dp1[prev];
                }
            }
        }
        
        for(int ind=n-1; ind>=0; ind--){
            for(int prev=n-1; prev>ind; prev--){
                
                if(nums[prev]<nums[ind] && dp2[ind]<dp2[prev]+1){
                    dp2[ind] =  1 + dp2[prev];
                }
            }
        }
        
        int maxi = 1;
        
        for(int i=0; i<n; i++){    
            if(dp1[i]!=1 && dp2[i]!=1)  // if LSI is 1 then it does not form mountain same RSI is one then also so we ignore index
            maxi = max(maxi, dp1[i]+dp2[i]-1); // calulating max element delete to form increasing subsequnce 
        }
        
        ans = n - maxi;
        return ans;
        
    }
};