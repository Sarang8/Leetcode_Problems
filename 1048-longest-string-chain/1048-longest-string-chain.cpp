class Solution {
public:
    bool compre(string &a, string &b){
        
        if(a.size()==b.size()) return false;
        
        if(b.size()-a.size() != 1) return false;
        
        int i=a.size()-1;
        int j=b.size()-1;
        
        while(j>=0){
            if(i>=0 && a[i]==b[j]){
                i--;
                j--;
            }
            else{
                j--;
            }
        }
        
        if(i<0 && j<0) return true;
        return false;
        
        
    }
    
    static bool cmpr(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    
    
    
    int longestStrChain(vector<string>& words) {
        
        int n=words.size();
        vector<int>dp(n, 1);
        int maxi=1;
        
        sort(words.begin(), words.end(), cmpr);
        
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                
                if(compre(words[prev], words[i]) && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
                 maxi=max(dp[i], maxi);
            }
           
        }
        return maxi; 
    }
};