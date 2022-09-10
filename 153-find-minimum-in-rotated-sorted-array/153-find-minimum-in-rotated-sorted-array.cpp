class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1) return nums[0];
        
        int low=0;
        int high=n-1;
        
        while(low<=high){
            
            
            
            int  mid = low+(high-low)/2;
            
            if(nums[low]<=nums[high]){
                return nums[low];
            }
            
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            
            if(nums[mid]<=nums[prev] && nums[next]>=nums[mid]){
                return nums[mid];
            }
            else if(nums[low]<=nums[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        
        }
           
        return nums[0];
        
    }
};