class Solution {
public:
    int solve(int ops, int i, vector<int>&n, vector<int>&m,  vector<vector<int>>&dp){
        
        if(ops>=m.size()){
            return 0;
        }
        
        int j = n.size()-1-ops+i;  //instead of having right as one of the state variables, we calculate it here itself
        

        
        if(dp[ops][i]!=INT_MIN) return dp[ops][i];
        
        int t1=0,t2=0;
        
        t1 += n[i]*m[ops] + solve(ops+1, i+1,n, m,dp);
        t2 += n[j]*m[ops] + solve(ops+1, i, n,m,dp);
        
        
        
        return dp[ops][i]=max(t1, t2);
        
        
    }
    
    
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int n = nums.size();
        int m=multipliers.size();
        vector<vector<int>>dp(m+1, vector<int>(m+1, INT_MIN));
        return solve(0, 0, nums, multipliers, dp);
        
        
        
        
    }
};