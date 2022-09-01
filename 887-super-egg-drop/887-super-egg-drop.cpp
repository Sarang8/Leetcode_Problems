class Solution {
public:
    
    int solve(int e, int f, vector<vector<int>>&dp){
        
        if(e==1){
            return f;
        }
        if(f==0 or f==1){
            return f;
        }
        
        if(dp[e][f]!=-1){
            return dp[e][f];
        }
        
        
        int mini=INT_MAX;
        
        int low = 1;
        int high = f;
        
        while(low<=high){
            
            int k = low + (high-low)/2;
            
            
            int right = solve(e, f-k, dp);
            int left = solve(e-1, k-1, dp);
            
            mini = min(mini, 1 + max(right, left));
            
            if(left<right){
                low = k + 1;
            }
            else{
                high = k-1;
            }        
        }
        
        // for(int k=1; k<=f;k++){
        //     mini = min(mini, 1 + max(solve(e-1, k-1), solve(e, f-k)));
        // }
        
        return dp[e][f] = mini;
        
    }
    
    
    
    
    int superEggDrop(int k, int n) {
        
        vector<vector<int>>dp(k+1, vector<int>(n+1, -1));
        return solve(k, n, dp);
        
    }
};