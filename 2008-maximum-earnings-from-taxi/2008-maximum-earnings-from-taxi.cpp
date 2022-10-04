#define ll long long
class Solution {
public:
    long long solve(int ind, vector<vector<int>>& rides, vector<int>&start, vector<ll>&dp){
        
        if(ind>=rides.size()){
            return 0;
        }
        
        if(dp[ind]!=-1) return dp[ind];
        
        //pick
        int nextInd = lower_bound(start.begin(), start.end(), rides[ind][1])-start.begin();
        ll pick = (rides[ind][1]-rides[ind][0]+rides[ind][2]) + solve(nextInd, rides, start, dp);
        
        //NotPick
        ll notPick = solve(ind+1, rides, start, dp);
        return dp[ind]=max(pick, notPick);        
    }
        
        
        
        
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        
        int m=rides.size();
        sort(rides.begin(), rides.end());
        vector<int>start;
        
        for(auto it:rides){
            start.push_back(it[0]);
        }
        
        vector<ll>dp(m+1,-1);
        
        return solve(0,rides, start, dp);
    }
};