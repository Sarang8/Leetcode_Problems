// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function Template for C++



class Solution{
  public:
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  int carAssembly(vector<vector<int>>& a, vector<vector<int>>& T, vector<int>& e, vector<int>& x){
      //Code Here
      int n=a[0].size();
      
      vector<int>T1(n,0);
      vector<int>T2(n,0);
      
      T1[0] = e[0] + a[0][0];
      T2[0] = e[1]+a[1][0];
      
      for(int i=1; i<n; i++){
          
          T1[i] = min( (T1[i-1]+a[0][i]), (T2[i-1]+a[0][i]+T[1][i]));
          T2[i] = min( (T2[i-1]+a[1][i]), (T1[i-1]+a[1][i]+T[0][i]));
    
      }
      
      return min(T1[n-1]+x[0], T2[n-1]+x[1]);
    
  }
};

// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(2,vector<int>(n)), T(2,vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>T[i][j];
            }
        }   
        vector<int> e(2), x(2);
        for(int i=0;i<2;i++){
            cin>>e[i];
        }
        for(int i=0;i<2;i++){
            cin>>x[i];
        }
        
        Solution ob;
        int ans = ob.carAssembly(a,T,e,x);
        
        cout<<ans<<endl;
    }
}  // } Driver Code Ends