class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>&ans ){
        
        if(ind==nums.size()){
            ans.push_back(ds);
            return;
        }
        
        
        
        ds.push_back(nums[ind]);
        solve(ind+1, nums, ds, ans);
        ds.pop_back();
        
        solve(ind+1, nums, ds, ans);
        
        
    }
    
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,nums, ds, ans);
        return ans;
    }
};