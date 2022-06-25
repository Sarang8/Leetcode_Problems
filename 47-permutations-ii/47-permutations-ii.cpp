class Solution {
public:
    
    void solve(int ind, vector<int>& nums, set<vector<int>>&s){
        
        if(ind==nums.size()){
            s.insert(nums);
            return;
        }
        
        for(int i=ind; i<nums.size(); i++){
            swap(nums[i], nums[ind]);
            solve(ind+1, nums, s);
            swap(nums[i], nums[ind]);
        }   
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>>ans;
        set<vector<int>>s;
        solve(0, nums, s);
        
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
        
        
    }
};