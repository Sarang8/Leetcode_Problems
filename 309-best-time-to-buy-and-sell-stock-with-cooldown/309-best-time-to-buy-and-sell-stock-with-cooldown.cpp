class Solution {
public:
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>>&dp){
        
        if(i>=prices.size()){
            return 0;
        }
        
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        
        int t1=0,t2=0;
        if(buy){
            t1=max(-prices[i]+solve(i+1, 0, prices, dp), -0+solve(i+1, 1, prices, dp));
        }
        else{
            t2=max(prices[i]+solve(i+2, 1, prices, dp), 0+solve(i+1, 0, prices, dp));
        }
        
        return dp[i][buy]=max(t1, t2);
        
        
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
        
    }
};