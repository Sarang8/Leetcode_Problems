// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    int dp[10005];
    
    int solve(int n, int x, int y, int z){
        
        if(n==0)  return 0;
        if(n<0) return -1e8;
        
        if(dp[n]!=-1) return dp[n];
        
        int xs = 1+solve(n-x, x,y,z);
        int ys = 1+solve(n-y, x,y,z);
        int zs = 1+solve(n-z, x,y,z);
        
        return dp[n] = max(xs, max(ys,zs));
    }
    
    
    
    
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp,-1, sizeof(dp));
        int maxi = solve(n, x, y,z);
        if(maxi<0) return 0;
        else return maxi;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends