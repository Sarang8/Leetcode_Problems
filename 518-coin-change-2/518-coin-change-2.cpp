class Solution {
public:
    
    int solve(int ind,int amount, vector<int>& coins, vector<vector<int>>&dp){
        
        if(amount==0){
            return 1;
        }
        
        if(ind<0){
            return 0;
        }
        
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        if(coins[ind]<=amount){
            return dp[ind][amount]=solve(ind, amount-coins[ind], coins, dp) + solve(ind-1, amount, coins, dp);
        }
        else{
            return dp[ind][amount] = solve(ind-1, amount, coins, dp);
        }    
    }
    
    
    
    
    
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        return  solve(n-1, amount ,coins, dp);
        
        
        
        
    }
};