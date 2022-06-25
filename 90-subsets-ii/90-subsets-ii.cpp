class Solution {
public:
    
//     void findSubset(int ind, vector<int>& nums, vector<int>&v, vector<vector<int>>&ans){
//         ans.push_back(v);
        
//         for(int i=ind; i<nums.size(); i++){
//             if(i!=ind && nums[i]==nums[i-1]){
//                 continue;
//             }
//             v.push_back(nums[i]);
//             findSubset(i+1, nums, v, ans);
//             v.pop_back();
//         }
//     }
    
    void solve(int ind, vector<int>& nums, vector<int>&ds, vector<vector<int>>&ans){
        
        ans.push_back(ds);
        
        for(int i=ind; i<nums.size(); i++){
            
            if(i!=ind && nums[i]==nums[i-1]){
                continue;
            }
            
            ds.push_back(nums[i]);
            solve(i+1, nums, ds, ans);
            ds.pop_back();
        }    
    }    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums){ 
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(), nums.end());
        solve(0, nums, ds, ans);
        return ans;
    
//     vector<vector<int>> ans;
//     set<vector<int>>s;
    
//     void solve(vector<int>nums, vector<int>op){
        
//         if(nums.size()==0){
            
//             if(s.find(op)==s.end()){
//                 s.insert(op);
//                 ans.push_back(op);
//             }
//             return;
//         }
        
//         vector<int>op1=op;
//         vector<int>op2=op;
        
//         op2.push_back(nums[0]);
//         nums.erase(nums.begin()+0);
        
//         solve(nums, op1);
//         solve(nums, op2);
        
//         return;
        
//     }

//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
//         // sort(nums.begin(),nums.end());
//         // vector<int>op;
//         // solve(nums, op);
//         // return ans;
//     }
  }
};