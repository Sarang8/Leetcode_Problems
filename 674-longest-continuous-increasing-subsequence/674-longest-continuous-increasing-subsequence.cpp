class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int i=0;
        int ans=0;
        int mx=0;
        
        while(i<n-1){
            
            if(nums[i]<nums[i+1]){
                mx++;
            }
            else{
               mx=0;    
            }
            i++;
            ans=max(ans, 1+mx);  
        }
        return ans;
    }
};