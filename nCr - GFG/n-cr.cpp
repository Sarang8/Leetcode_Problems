// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1e9+7;
    int solve(int n, int r, vector<vector<int>>&dp){
        
        if(n==0 or r==0){
            return 1;
        }
        if(n==r){
            return 1;
        }
        if(dp[n][r]!=-1){
            return dp[n][r];
        }
        
        int x = solve(n-1, r-1, dp);
        int y = solve(n-1, r, dp);
        return dp[n][r] = (x+y)%mod;
    }

    int nCr(int n, int r){
        // code here
       if(n<r) return 0;
    //   vector<vector<int>>dp(n+1, vector<int>(r+1, -1));
    //   return solve(n, r, dp);
    
        vector<vector<int>>dp(n+1, vector<int>(r+1,0));
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<r+1; j++){
                
                if(i==0 or j==0){
                    dp[i][j]=1;
                }
            }
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<r+1; j++){
                
                if(i==j){
                    dp[i][j]=1;
                }
                else{
                    int x = dp[i-1][j-1];
                    int y = dp[i-1][j];
                    
                    dp[i][j] = (x+y)%mod;
                }
                
            }
        }
        
       return dp[n][r]%mod;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends