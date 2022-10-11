class Solution {
public:
    bool solve(int ind, string &s, unordered_set<string>&dict, vector<int>&dp){
        
        if(ind>=s.size()){
            return true;
        }
        
        if(dp[ind]!=-1) return dp[ind];
        
        string temp ="";
        
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            if(dict.find(temp)!=dict.end()){
                if(solve(i+1, s, dict, dp)){
                    return dp[ind]=true;
                }
            }
        }
        
        return dp[ind]=false;
        
    }
    
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n=s.size();
        unordered_set<string>dict(wordDict.begin(), wordDict.end());
        vector<int>dp(n+1, -1);
        return solve(0, s, dict, dp);
        
        
        
    }
};