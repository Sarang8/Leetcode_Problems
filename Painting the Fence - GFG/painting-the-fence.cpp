// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int mod = 1e9+7;
    // int dp[5005];
    
    // long long solve(int n, int k){
        
    //     if(n==1)  return k;
        
    //     if(n==2)  return (k+k*(k-1))%mod;
        
    //     if(dp[n] != -1) return dp[n];
        
    //     int same = ((k-1)*solve(n-2, k))%mod;
    //     int diff = ((k-1)*solve(n-1, k))%mod;
        
    //     return dp[n]=(same+diff)%mod;
    // }
    
    
    
    
    long long countWays(int n, int k){
        // code here
        // memset(dp,-1,sizeof(dp));
        // return solve(n,k);
        
        vector<long long>dp(n+1);
        
        dp[1] = k;
        dp[2] = k+k*(k-1);
        
        for(int i=3; i<n+1; i++){
            
            int same = ((k-1)*dp[i-2])%mod;
            int diff = ((k-1)*dp[i-1])%mod;
            
            dp[i]=(same+diff)%mod;
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
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends