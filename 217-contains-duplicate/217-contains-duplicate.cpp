class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int, int>m;
        
//         for(int i=0; i<n; i++){
//             m[nums[i]]++;
//         }
        
//         for(auto it:m){
//             if(it.second>=2)
//                     return true;
//         }
//         return false;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++) if(nums[i] == nums[i+1]) return true;
        return false;
        
    }
};