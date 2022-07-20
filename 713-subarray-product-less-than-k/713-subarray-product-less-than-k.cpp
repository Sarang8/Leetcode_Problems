class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n=nums.size();
        //sort(nums.begin(), nums.end());
        
        if(k==0) return 0;
        
        int i=0;
        int j=0;
        int ans=0;
        long long temp=1;
        
        while(j<n){
            
            temp=temp*nums[j];
            
            if(temp>=k){
                while(temp>=k && i<j){
                    temp=temp/nums[i];
                    i++;
                }
            }
            
            if(temp<k){
                ans+=(j-i+1);   
            }
           j++;
        }
        
        return ans;
    }
};