class Solution {
public:
   
    bool solve(int i, int j, string &s, string &p, vector<vector<int>>&dp){
        
        
        if(i>=s.size() && j>=p.size()){
            return true;
        }
        
        if(j>=p.size()){
            return false;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        bool match = (i<s.size() && (s[i]==p[j] or p[j]=='.'));
        
        if( j+1 < p.size() &&  p[j+1]=='*'){
            
            return dp[i][j] =   solve(i, j+2, s, p, dp) or    //NOT TAKE STAR
                                (match && solve(i+1, j,s,p,dp));       //STAR TAKEN
            
        }
        
        if(match==true){
            return dp[i][j]=solve(i+1, j+1,s,p,dp);
        }
        
        return false;
        
    }
    
    
    
    bool isMatch(string s, string p) {
        
        int n=s.size();
        int m=p.size();
        //memset(dp,-1,sizeof(dp));
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        
        return solve(0, 0, s, p, dp);
        
    }
};