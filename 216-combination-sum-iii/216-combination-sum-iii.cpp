class Solution {
public:
    
    void solve(int ind,int target,vector<int>&ds,vector<vector<int>>&ans, int k){
            
        if(target==0 && ds.size()==k){
            ans.push_back(ds);
            return;
        }
        
        
        for(int i=ind; i<=9; i++){
            ds.push_back(i);
            solve(i+1, target-i, ds,ans,k);
            ds.pop_back();
        }   
    }
    
    
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;

        solve(1, n, ds, ans,k);
        
       
        return ans;
        
    }
};