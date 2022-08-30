class Solution {
public:
    
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
        
        if(i<0 && j<0){
            return 0;
        }
        
        if(i<0 && j>=0){
            int ans=0;
            for(int p=j;p>=0;p--){
                ans = ans + int(s2[p]);
            }
            return ans;
        }
        
        if(j<0 && i>=0){
            int ans=0;
            for(int p=i;p>=0;p--){
                ans = ans + int(s1[p]);
            }
            return ans;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s1[i]==s2[j]){
            return dp[i][j]=solve(i-1, j-1, s1, s2, dp);
        }
        
        else{
            int asc1 = int(s1[i]) + solve(i-1, j, s1, s2, dp);
            int asc2 = int(s2[j]) + solve(i, j-1, s1,s2, dp);
            return dp[i][j]=min(asc1, asc2);
        }        
    }
    
    
    
    int minimumDeleteSum(string s1, string s2) {
        
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        
        return solve(n-1, m-1, s1, s2, dp);
        
    }
};