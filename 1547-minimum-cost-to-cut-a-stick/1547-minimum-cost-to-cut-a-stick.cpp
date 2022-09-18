class Solution {
public:
    
    int solve(int i, int j, vector<int>&cuts, vector<vector<int>>&dp){
        
        if(i>j){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=INT_MAX;
        for(int k=i; k<=j; k++){
            int cost=0;
            cost = cuts[j+1]-cuts[i-1] + solve(i, k-1, cuts, dp) + solve(k+1, j, cuts, dp);
            ans = min(ans , cost);  
            
        }
        
        return dp[i][j]=ans;
    }
    
    
    
    
    
    
    int minCost(int n, vector<int>& cuts) {
        
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int size = cuts.size();
        vector<vector<int>>dp(size+1, vector<int>(size+1, -1));
        
        return solve(1, size-2, cuts, dp);
        
        
        
        
//         vector<vector<int>>dp(size+2, vector<int>(size+2, 0));
        
        
//         for(int i=size; i>=1; i--){
//             for(int j=1; j<=size; j++){
                
//                 if(i>j) continue;
                
//                 int mini=INT_MAX;
//                 for(int ind=i; ind<=j; ind++){
//                     int cost = cuts[j+1]-cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
//                     mini = min(mini, cost);
//                 }
//                 dp[i][j] = mini;
//             }
//         }
        
//         return dp[1][size];
    }
};