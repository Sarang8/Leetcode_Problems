class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int count=1;
        int start=0;
        for(int i=0; i<nums.size(); i++){
            
            if(nums[i]-nums[start] >k){
                start = i;
                count++;
            }
            
        }
        return count;
        
        
        
        
        
    }
};