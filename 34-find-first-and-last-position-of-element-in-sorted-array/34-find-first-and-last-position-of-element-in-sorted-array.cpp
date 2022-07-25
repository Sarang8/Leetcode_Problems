class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n=nums.size();
        int s=0;
        int e=n-1;
        int fo=-1;
        int lo=-1;
        vector<int>ans(2,0);
        
        while(s<=e){
            int mid=s+(e-s)/2;
            
            if(nums[mid]==target){
                fo=mid;
                e=mid-1;
            }
            
            else if(nums[mid]>target){
                e=mid-1;
            }
            
            else{
                s=mid+1;
            }    
        }
        
        s=0;
        e=n-1;
        
        while(s<=e){
            
           int mid=s+(e-s)/2;
            
            if(nums[mid]==target){
                lo=mid;
                s=mid+1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }   
        }
        
        ans[0]=fo;
        ans[1]=lo;
        return ans;
    }
};