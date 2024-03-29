class Solution {
public:
    
bool isPalindrome(int low,int high,string &s){
        while(low<high){
            if(s[low++]!=s[high--]){
                return false;
            }
        }
        return true;
    }
    
    
    
    int solve(int i,string s,vector<int>&dp){
        int n=s.size();
        if(i==n){
            return 0;
        }
        
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                mini=min(mini,1+solve(j+1,s,dp));
            }
        }
        return dp[i]=mini;
    }
    
    
    
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,s,dp)-1;
    }
};