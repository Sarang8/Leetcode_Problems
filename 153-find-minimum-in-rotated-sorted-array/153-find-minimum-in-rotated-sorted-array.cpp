class Solution {
public:
    int findMin(vector<int>& nums) {
        
        
        int s=0;
        int e = nums.size()-1;
        int N = nums.size();
        
        if(N==1){
            return nums[0];
        }
        
        while(s<=e){
            
             
            if(nums[s]<=nums[e]){
                return nums[s];
            }
            
            int mid = s + (e-s)/2;
            
            int prev = (mid-1+N)%N;
            int nxt = (mid+1)%N;
            
           
            
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[nxt])
                return nums[mid];
            
            else if(nums[s]<=nums[mid]){
                s = mid+1;
            }
            
            else{ 
                e = mid-1;    
            }
        }
          return nums[0];
        
    }
};