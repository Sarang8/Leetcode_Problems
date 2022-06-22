// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    // long long int dp[10001];
    // int mod = (int)1e9+7;
    // int solve(int n){
    //     if(n==1){
    //         return 1;
    //     }
    //     if(n==2){
    //         return 2;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
        
    //     long long int  single = solve(n-1);
    //     long long int  pair = (n-1)*solve(n-2);
        
    //     return dp[n]=(single + pair)%mod;
    // }
    
    
    int countFriendsPairings(int n) 
    { 
        // code here
        
        // memset(dp,-1, sizeof(dp));
        // return (int)solve(n);
        vector<long long>dp(n+1,0);
        int mod=1e9+7;
        
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i=3; i<n+1; i++){
            
           long long int  single = dp[i-1];
           long long int  pair = (i-1)*dp[i-2];
        
            dp[i] = (single + pair)%mod;
        }
        
        return dp[n];
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends