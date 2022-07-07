class Solution {
public:
    int  helper(string& s,int ind,int n,vector<int>& dp)
    {
        if(ind==n)
            return 1;
        if(s[ind]=='0') //since we cannot decode it
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int sum=0;
        //consider a single number to decode
        sum+=helper(s,ind+1,n,dp);
        
        //consider two digits if they are in range from 1-26
        if(ind+1<n && (s[ind]-'0')*10 + (s[ind+1]-'0') <=26)
        {
            sum+=helper(s,ind+2,n,dp);
        }
        dp[ind]=sum;
        return dp[ind];
    }
   int numDecodings(string s) {
        //dp [i] stores the result for substring i-len
        //i.e., dp[i] stores the number of ways in which we can decode the substring from i to len-1
        int len=s.length();
        vector<int> dp(len,-1);
        helper(s,0,len,dp);
        return dp[0]==-1 ? 0 : dp[0];
    }
    
};