class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        int n = nums.size();
        unordered_map<int,int>m;
        
        for(int i=0; i<n; i++){
            m[nums[i]]=i;
        }
        
        for(int i=0; i<operations.size(); i++){
            
            int a = operations[i][0];
            int b = operations[i][1];
            
            nums[m[a]] = b;
            m[b] = m [a];
        }
        
        return nums;
           
    }
};