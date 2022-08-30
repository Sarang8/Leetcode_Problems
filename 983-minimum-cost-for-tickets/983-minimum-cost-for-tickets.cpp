class Solution {
public:
    
    int solve(vector<int>& days, vector<int>& costs, int ind, int validity, vector<vector<int>>&dp){
        
        if(ind>=days.size()){
            return 0;
        }
        
        if(dp[ind][validity]!=-1){
            return dp[ind][validity];
        }
        
        
        if(days[ind]<= validity){
            return dp[ind][validity] = solve(days, costs, ind+1, validity,dp);
        }
        else{
            int c1 = costs[0]+solve(days, costs, ind+1, days[ind],dp);
            int c2 = costs[1]+solve(days, costs, ind+1, days[ind]+6 , dp);
            int c3 = costs[2]+solve(days, costs, ind+1, days[ind]+29, dp);
            return dp[ind][validity]=min(c1, min(c2, c3));
        }
    }
    
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n=days.size();
        int max_validity = days[n-1]+30;
        
        vector<vector<int>>dp(n, vector<int>(max_validity, -1));
        return solve(days, costs, 0,0, dp);
    
    }
};