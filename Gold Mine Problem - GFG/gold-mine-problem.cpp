// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[55][55];
    
    int solve(int i, int j ,vector<vector<int>>& M, int n, int m){
        
        if(i<0 or i>=n){
            return -1e9;
        }
        if(j==m-1){
            return M[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int straight = M[i][j]+ solve(i, j+1, M,n,m);
        int diagDown = M[i][j]+ solve(i+1, j+1, M,n,m);
        int diagUp =  M[i][j]+ solve(i-1, j+1, M,n,m);
    
        return dp[i][j] = max(straight, max(diagDown,diagUp));
        
    }



    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        int mx=INT_MIN;
        for(int i=0; i<n; i++){
            mx = max(mx, solve(i, 0,M,n,m));
        }
        
        return mx;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends