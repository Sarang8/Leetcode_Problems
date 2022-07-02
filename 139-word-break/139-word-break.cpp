class Solution {
public:
    bool solve(string s, unordered_set<string>&dictionry){
        
        if(dictionry.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dictionry.find(word)!= dictionry.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];    
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string>dictionry;
        for(int i=0; i<wordDict.size(); i++){
            dictionry.insert(wordDict[i]);
        }
        
        return solve(s,dictionry);
    }
};