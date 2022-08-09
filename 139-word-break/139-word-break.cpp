class Solution {
public:
    
//     bool solve(string s, unordered_set<string>&dictionry){
        
//         if(dictionry.size()==0) return false;
        
//         vector<bool> dp(s.size()+1,false);
//         dp[0]=true;
        
//         for(int i=1;i<=s.size();i++)
//         {
//             for(int j=i-1;j>=0;j--)
//             {
//                 if(dp[j]==true)
//                 {
//                     string word = s.substr(j,i-j);
//                     if(dictionry.find(word)!= dictionry.end())
//                     {
//                         dp[i]=true;
//                         break; 
//                     }
//                 }
//             }
//         }
        
//         return dp[s.size()];    
//     }
    
    
    int dp[301];
    
    
    int solve(int ind, string s,unordered_set<string>&dictionry){
        
        if(ind==s.size()){
            return 1;
        }
        
        if(dp[ind]!=-1) return dp[ind];
        
        
        string temp="";
        for(int i=ind; i<s.size(); i++){
            
            temp += s[i];
            if(dictionry.find(temp)!=dictionry.end()){
                if(solve(i+1, s, dictionry))
                    return dp[ind]=1;
            }
        }
        
        
        return dp[ind]=0;
    }
    
    
    
    bool wordBreak(string s, vector<string> wordDict) {
        
        // unordered_set<string>dictionry;
        // for(int i=0; i<wordDict.size(); i++){
        //     dictionry.insert(wordDict[i]);
        // }
        unordered_set<string> dictionry(wordDict.begin(), wordDict.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,s,dictionry);
    }
    
    

};