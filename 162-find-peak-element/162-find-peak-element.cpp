class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int s=0;
        int e=nums.size()-1;
        
        if(nums.size()==1){
            return 0;
        }
        
        while(s<=e){
            
            int mid = s + (e-s)/2;
            
            if(mid>0 && mid<(nums.size()-1)){
                
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                    return mid;
                }
                else if(nums[mid]<nums[mid-1]){
                    e = mid-1;
                }
                else {
                    s = mid+1;
                }
                 
            }
            
            else if(mid==0){
                if(nums[mid]>nums[mid+1]){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            
            else if(mid==nums.size()-1) {
                if(nums[mid]>nums[mid-1]){
                    return nums.size()-1;
                }
                else{
                    return mid-1;
                }
            }
                         
        }
        return -1;
        
    }
};