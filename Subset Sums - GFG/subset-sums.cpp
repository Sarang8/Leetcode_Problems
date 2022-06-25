// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    // void subsets(int start,int sum, vector<int>&ans, vector<int>&arr, int N){
        
    //     if(start == N){
    //         ans.push_back(sum);
    //         return;
    //     }
        
    //     subsets(start+1, sum+arr[start], ans, arr, N);   //Pick the element
        
    //     subsets(start+1, sum, ans, arr, N);         // Didint pick it
    
    // }

    void solve(int i, vector<int> arr, int sum, vector<int>&ans){
        if(i == arr.size()){
            ans.push_back(sum);
            return;
        }
        
        solve(i+1, arr, sum+arr[i], ans);
        
        solve(i+1, arr, sum, ans);
        
    }






    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        solve(0,arr,0,ans);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends