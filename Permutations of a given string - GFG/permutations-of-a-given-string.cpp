// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	    void solve(int ind, string &S, set<string>&set){
	        
	        if(ind==S.size()){
	            set.insert(S);
	            return;
	        }
	        
	        for(int i=ind; i<S.size(); i++){
	            
	            swap(S[i], S[ind]);
	            solve(ind+1, S, set);
	            swap(S[i], S[ind]);
	        }
	    }
	
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    set<string>set;
		    solve(0, S, set);
		    
		    for(auto it:set){
		        ans.push_back(it);
		    }
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends