class Solution {
public:
    void solve(int ind, vector<int>&nums, vector<int>&ds, vector<vector<int>>&ans, int k){
        
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }
        
        
        for(int i=ind; i<nums.size(); i++){
            
            ds.push_back(nums[i]);
            solve(i+1, nums, ds, ans, k);
            ds.pop_back(); 
        } 
    }
    
    
    
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<int>nums(n);
        
        for(int i=0; i<n; i++){
            nums[i]=i+1;
        }
        
        vector<vector<int>>ans;
        vector<int>ds;
        
        solve(0, nums, ds, ans, k);
        return ans;
    }
};