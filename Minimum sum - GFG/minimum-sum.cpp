// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        // priority_queue<int, vector<int>, greater<int>>pq;
        
        // for(int i=0; i<n; i++){
        //     pq.push(arr[i]);
        // }
        
        // string small1="";
        // string small2="";
        
        // while(!pq.empty()){
            
        //     small1 += to_string(pq.top());
        //     if(pq.size()>0){
        //         pq.pop();
        //     }
            
        //     if(pq.size()>0){
        //         small2 += to_string(pq.top());
        //         pq.pop();
        //     }
        // }
        
        // long long a = stoi(small1);
        // long long b = stoi(small2);
        
        // return to_string(a+b);
        
        string s1 = "";
        string s2 = "";
        
        // Sorting and taking the smallest 2 numbers into 2 string
        sort(arr, arr+n);
       
        for(int i=0;i<n;i=i+2){
            s1+=to_string(arr[i]);
            if(i+1 == n) break;
            s2+=to_string(arr[i+1]);
        }
    
        // if one of the number is smaller than the other ( s2 here ), we add a leading zero for addition
        if(s2.size() < s1.size()) s2 = '0'+s2;
        
        // String addition
        string res = "";
        int carry = 0;
        
        for(int i = s1.size()-1; i >= 0; i--){
            int sum = (s1[i] - '0') + (s2[i] - '0') + carry;
            carry = sum / 10;
            
            res = to_string(sum%10)+res;
        }
        
        res = to_string(carry)+res;
        
        // Removing leading zeros
        
        int i = 0;
        string final = "";
        while(i < res.size()){
            if(res[i] > '0') break;
            i++;
        }
        
        while(i < res.size()){
            final = final+res[i];
            i++;
        }
        
    
        return final;
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends